# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.

"""Unused cached ops packages must survive toolkit-only installation."""

import os
import subprocess
from pathlib import Path

import pytest

SCRIPT = Path(
    os.environ.get("INIT_ENV_SCRIPT", Path(__file__).parents[2] / "scripts/init_env.sh")
)


@pytest.mark.parametrize("install_ops", [False, True])
def test_cleanup_only_removes_selected_packages(tmp_path, install_ops):
    source = SCRIPT.read_text(encoding="utf-8")
    assert source.rstrip().endswith('main "$@"')
    source = source.rsplit('main "$@"', 1)[0]
    old = 'local download_dir="/tmp/cann_install"'
    assert old in source
    source = source.replace(old, 'local download_dir="$CASE_ROOT/cann_install"', 1)
    (tmp_path / "functions.sh").write_text(source, encoding="utf-8")
    download_dir = tmp_path / "cann_install"
    download_dir.mkdir()
    toolkit = download_dir / "Ascend-cann-toolkit_1.0_linux-x86_64.run"
    toolkit.write_text("#!/bin/sh\nexit 0\n", encoding="utf-8")
    ops = download_dir / "Ascend-cann-910b-ops_1.0_linux-x86_64.run"
    ops.write_bytes(b"#!/bin/sh\nexit 0\n" if install_ops else b"existing ops package")
    harness = r"""
source "$CASE_ROOT/functions.sh"
get_cann_url() { echo 'https://fixture.invalid'; }
get_arch() { echo x86_64; }
wget() { echo 'Ascend-cann-toolkit_1.0_linux-x86_64.run'; }
if [ "$USE_OPS" = 1 ]; then INSTALL_OPS=true; fi
install_cann
"""
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
    if install_ops:
        assert not ops.exists()
    else:
        assert ops.read_bytes() == b"existing ops package"
    assert not toolkit.exists()
