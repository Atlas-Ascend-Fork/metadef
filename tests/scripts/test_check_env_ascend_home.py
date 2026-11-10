# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.

"""Check the environment variable required by the build entry point."""

import os
import re
import subprocess
from pathlib import Path

import pytest

SCRIPT = Path(
    os.environ.get(
        "CHECK_ENV_SCRIPT", Path(__file__).parents[2] / "scripts/check_env.sh"
    )
)


@pytest.mark.parametrize("is_set", [False, True])
def test_ascend_home_path_required_even_when_toolkit_dir_exists(tmp_path, is_set):
    home = tmp_path / "home"
    toolkit = home / "Ascend/ascend-toolkit/latest"
    toolkit.mkdir(parents=True)
    env = {**os.environ, "HOME": str(home), "LC_ALL": "C.UTF-8"}
    env.pop("ASCEND_HOME_PATH", None)
    if is_set:
        env["ASCEND_HOME_PATH"] = str(toolkit)
    result = subprocess.run(
        ["/bin/bash", str(SCRIPT)],
        env=env,
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    plain = re.sub(r"\x1b\[[0-9;]*m", "", result.stdout)
    missing = any(
        "[ERROR]" in line and "ASCEND_HOME_PATH" in line for line in plain.splitlines()
    )
    assert missing is not is_set
    if not is_set:
        assert result.returncode != 0
