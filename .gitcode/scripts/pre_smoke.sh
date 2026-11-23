#!/bin/bash
# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

set -euo pipefail

echo "start run test case, please wait ..."
cd ${WORKSPACE}

export ASCEND_GLOBAL_LOG_LEVEL=2
export ASCEND_SLOG_PRINT_TO_STDOUT=0
source /usr/local/Ascend/cann/set_env.sh

log() {
  local dt
  dt=$(date '+%Y%m%d.%H%M%S')
  echo "===================================================================="
  echo "$dt : $*"
  echo "===================================================================="
}

package_slog() {
  if [ ! -f "${WORKSPACE}/slog.tar.gz" ] && [ -d /root/ascend/log ]; then
    tar -zcf "${WORKSPACE}/slog.tar.gz" -C /root/ascend log || true
  fi
}
trap package_slog EXIT

log "init test case, please wait ..."
rm -rf /root/ascend/log

# ==============================
# 下载 single.tar.gz
# ==============================
log "start run test case, please wait ..."

if [ -z "${run_url:-}" ]; then
    echo "[PreSmoke] run_url is empty (compile stage skipped or no artifact), no need to execute smoke test task"
    exit 0
fi

DOWNLOAD_FILE=$(basename "${run_url}")

# compile 阶段跳过时(仅改 md/docs 等文件), 产物为 0 字节的 empty.run 占位包,
# run_url 指向 .../empty.run。以此区分 "compile 跳过"(打日志后 exit 0)
# 与 "真实下载失败"(打日志后 exit 1)。
if [ "${DOWNLOAD_FILE}" = "empty.run" ]; then
    echo "[PreSmoke] Compile stage skipped (empty.run placeholder), no need to execute smoke test task"
    exit 0
fi

echo "Starting to download file: ${DOWNLOAD_FILE}"
if ! wget -nv --tries=3 --timeout=60 --no-clobber "${run_url}"; then
    echo "[PreSmoke] ERROR: failed to download ${DOWNLOAD_FILE} from ${run_url}" >&2
    exit 1
fi

if [ ! -f "${DOWNLOAD_FILE}" ]; then
    echo "[PreSmoke] ERROR: ${DOWNLOAD_FILE} does not exist after download (url: ${run_url})" >&2
    exit 1
fi

FILE_SIZE=$(stat -c%s "${DOWNLOAD_FILE}")
if [ "${FILE_SIZE}" -eq 0 ]; then
    echo "[PreSmoke] No compiled operators (0-byte package from ${run_url}), no need to execute smoke test task"
    rm -f "${DOWNLOAD_FILE}"
    exit 0
fi


# ==============================
# 运行测试
# ==============================

# bash CI/cann/public/install_miniconda.sh
# source ~/.bashrc
pip3 install numpy
echo 'y' | bash "${DOWNLOAD_FILE}" --full --install-path=/usr/local/Ascend 2>&1 | tee -a ./run_test.log && source /usr/local/Ascend/cann/set_env.sh
cd example || exit 1
bash run_example.sh 2>&1 | tee -a "${WORKSPACE}/run_test.log"
cd - || exit 1

# ==============================
# 打包log
# ==============================
mkdir -p /root/ascend
slog_name="slog.tar.gz"
cd ${WORKSPACE}
tar -zcf "${slog_name}" -C /root/ascend log

# upload plog
# if python3 /home/upload.py --bucket-name "ascend-ci" --action upload  --local-file "slog.tar.gz" --obs-object-key "${repo_name}/package/${pr_id}/${slog_name}"; then
#   echo "::set-output var=plog_url:https://ascend-ci.obs.cn-north-4.myhuaweicloud.com/${repo_name}/package/${pr_id}/slog.tar.gz"
# fi

# ==============================
# 检查 NPU 状态
# ==============================
log "checking NPU status ..."
mkdir -p ./npu_log
npu-smi info  2>&1 | tee ./npu_log/npu_info.log

# ==============================
# 检查测试结果
# ==============================
log "checking test results ..."

date_time=$(date +%Y%m%d)"."$(date +%H%M%S)
if grep -iE '\b(FAIL|failed|error:)\b' "./run_test.log" | grep -viE "error\)|Version compatibility check failed"; then
    echo "$date_time : run test case failed"
    exit 1
fi
