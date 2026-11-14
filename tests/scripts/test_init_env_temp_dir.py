# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.

"""The download directory must be private, ephemeral, and fully cleaned up."""

import os
import subprocess
from pathlib import Path

import pytest

SCRIPT = Path(
    os.environ.get("INIT_ENV_SCRIPT", Path(__file__).parents[2] / "scripts/init_env.sh")
)

WGET_FIXTURE = r"""
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
    stat -c '%a' "$PWD" > "$CASE_ROOT/dir_mode"
    printf '#!/bin/sh\nexit 0\n' > "$output"
}
"""


def _functions_source() -> str:
    source = SCRIPT.read_text(encoding="utf-8")
    assert source.rstrip().endswith('main "$@"')
    return source.rsplit('main "$@"', 1)[0]


@pytest.mark.parametrize("install_ops", [False, True])
def test_only_selected_packages_downloaded_and_dir_cleaned(tmp_path, install_ops):
    source = _functions_source()
    old = "download_dir=$(mktemp -d)"
    assert old in source
    source = source.replace(
        old, 'download_dir="$CASE_ROOT/cann_install"; mkdir -p "$download_dir"', 1
    )
    (tmp_path / "functions.sh").write_text(source, encoding="utf-8")
    harness = (
        'source "$CASE_ROOT/functions.sh"\n'
        + WGET_FIXTURE
        + 'if [ "$USE_OPS" = 1 ]; then INSTALL_OPS=true; fi\n'
        + "install_cann\n"
    )
    result = subprocess.run(
        ["/bin/bash", "-c", harness],
        env={
            **os.environ,
            "CASE_ROOT": str(tmp_path),
            "USE_OPS": "1" if install_ops else "0",
        },
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    assert result.returncode == 0, result.stderr
    downloads = (tmp_path / "downloads").read_text(encoding="utf-8").splitlines()
    if install_ops:
        assert downloads == ["toolkit", "ops"]
    else:
        assert downloads == ["toolkit"]
    assert not (tmp_path / "cann_install").exists()


def test_download_dir_is_private_0700_and_removed(tmp_path):
    (tmp_path / "functions.sh").write_text(_functions_source(), encoding="utf-8")
    harness = (
        'source "$CASE_ROOT/functions.sh"\n'
        + WGET_FIXTURE
        + r"""
mktemp() {
    local out
    out=$(command mktemp "$@")
    if [ "$1" = -d ]; then echo "$out" > "$CASE_ROOT/dir_path"; fi
    echo "$out"
}
install_cann
"""
    )
    result = subprocess.run(
        ["/bin/bash", "-c", harness],
        env={**os.environ, "CASE_ROOT": str(tmp_path)},
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    assert result.returncode == 0, result.stderr
    dir_path = (tmp_path / "dir_path").read_text(encoding="utf-8").strip()
    assert os.path.isabs(dir_path)
    assert (tmp_path / "dir_mode").read_text(encoding="utf-8").strip() == "700"
    assert not Path(dir_path).exists()
