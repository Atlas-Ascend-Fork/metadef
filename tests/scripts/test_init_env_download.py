# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.

"""Exercise interrupted package downloads without a CANN installation."""

import os
import subprocess
from pathlib import Path

import pytest

SCRIPT = Path(
    os.environ.get("INIT_ENV_SCRIPT", Path(__file__).parents[2] / "scripts/init_env.sh")
)

HARNESS = r"""
source "$CASE_ROOT/functions.sh"
get_cann_url() { echo 'https://fixture.invalid'; }
get_arch() { echo x86_64; }
wget() {
    local output='' url=''
    while [ "$#" -gt 0 ]; do
        if [ "$1" = '-O' ]; then output="$2"; shift 2; else url="$1"; shift; fi
    done
    if [ "$output" = '-' ]; then
        echo 'Ascend-cann-toolkit_1.0_linux-x86_64.run'
        return 0
    fi
    local kind=toolkit
    case "$url" in *-ops_*) kind=ops ;; esac
    echo "$kind" >> "$CASE_ROOT/downloads"
    if [ "$kind" = "$FAIL_KIND" ] && [ ! -e "$CASE_ROOT/failed-once" ]; then
        touch "$CASE_ROOT/failed-once"
        printf 'partial download\n' > "$output"
        return 1
    fi
    printf '#!/bin/sh\nexit 0\n' > "$output"
}
if [ "$FAIL_KIND" = ops ]; then INSTALL_OPS=true; fi
if [ "${PREFILL:-0}" = 1 ]; then
    mkdir -p "$CASE_ROOT/cann_install"
    printf '#!/bin/sh\nexit 0\n' > "$CASE_ROOT/cann_install/Ascend-cann-toolkit_1.0_linux-x86_64.run"
fi
if install_cann > "$CASE_ROOT/first.log" 2>&1; then first=0; else first=$?; fi
if install_cann > "$CASE_ROOT/second.log" 2>&1; then second=0; else second=$?; fi
printf 'first=%s second=%s\n' "$first" "$second"
"""


@pytest.mark.parametrize("kind", ["toolkit", "ops"])
def test_interrupted_download_is_retried(tmp_path, kind):
    source = SCRIPT.read_text(encoding="utf-8")
    assert source.rstrip().endswith('main "$@"')
    source = source.rsplit('main "$@"', 1)[0]
    old = 'local download_dir="/tmp/cann_install"'
    assert old in source
    source = source.replace(old, 'local download_dir="$CASE_ROOT/cann_install"', 1)
    (tmp_path / "functions.sh").write_text(source, encoding="utf-8")
    result = subprocess.run(
        ["/bin/bash", "-c", HARNESS],
        env={**os.environ, "CASE_ROOT": str(tmp_path), "FAIL_KIND": kind},
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    assert result.returncode == 0, result.stderr
    assert "first=1 second=0" in result.stdout, (tmp_path / "second.log").read_text(
        encoding="utf-8"
    )
    downloads = (tmp_path / "downloads").read_text(encoding="utf-8").splitlines()
    assert downloads.count(kind) == 2
    if kind == "ops":
        assert downloads.count("toolkit") == 1


def test_completed_existing_package_is_reused(tmp_path):
    source = SCRIPT.read_text(encoding="utf-8").rsplit('main "$@"', 1)[0]
    source = source.replace(
        'local download_dir="/tmp/cann_install"',
        'local download_dir="$CASE_ROOT/cann_install"',
        1,
    )
    (tmp_path / "functions.sh").write_text(source, encoding="utf-8")
    result = subprocess.run(
        ["/bin/bash", "-c", HARNESS],
        env={
            **os.environ,
            "CASE_ROOT": str(tmp_path),
            "FAIL_KIND": "none",
            "PREFILL": "1",
        },
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    assert result.returncode == 0, result.stderr
    assert "first=0 second=0" in result.stdout
    assert "Downloading CANN toolkit" not in (tmp_path / "first.log").read_text(
        encoding="utf-8"
    )
    assert (tmp_path / "downloads").read_text(encoding="utf-8").splitlines() == [
        "toolkit"
    ]
