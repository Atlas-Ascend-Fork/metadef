# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.

"""Exercise the environment check with controlled Python executables."""

import os
import re
import shutil
import subprocess
from pathlib import Path

import pytest

SCRIPT = Path(
    os.environ.get(
        "CHECK_ENV_SCRIPT", Path(__file__).parents[2] / "scripts/check_env.sh"
    )
)


@pytest.mark.parametrize(
    ("version", "expected"),
    [
        (None, "未安装 Python3"),
        ("3.8.0", "Python 版本过低"),
        ("unknown", "Python 版本过低或无法识别"),
        ("broken", "无法运行 python3 --version"),
        ("3.9.0", "Python 3.9.0"),
        ("3.10.2", "Python 3.10.2"),
    ],
)
def test_python_dependency_is_checked(tmp_path, version, expected):
    path = tmp_path / "bin"
    path.mkdir()
    for tool in (
        "uname",
        "date",
        "grep",
        "cut",
        "tr",
        "sort",
        "head",
        "ls",
        "nproc",
        "free",
        "df",
    ):
        executable = shutil.which(tool)
        if executable:
            (path / tool).symlink_to(executable)
    if version:
        python = path / "python3"
        version_command = (
            "exit 1" if version == "broken" else f'echo "Python {version}"'
        )
        python.write_text(
            '#!/bin/sh\nif [ "$1" = "--version" ]; then '
            + version_command
            + '; elif [ "$1" = "-m" ]; then '
            + 'echo called >> "$PIP_CALL_LOG"; echo "pip 25.0"; fi\n',
            encoding="utf-8",
        )
        python.chmod(0o755)
    result = subprocess.run(
        ["/bin/bash", str(SCRIPT)],
        env={
            **os.environ,
            "PATH": str(path),
            "LC_ALL": "C.UTF-8",
            "PIP_CALL_LOG": str(tmp_path / "pip-calls"),
        },
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    plain = re.sub(r"\x1b\[[0-9;]*m", "", result.stdout)
    line = next((line for line in plain.splitlines() if expected in line), "")
    supported = version in ("3.9.0", "3.10.2")
    assert ("[PASS]" if supported else "[ERROR]") in line
    if supported:
        assert "pip 25.0" in result.stdout
        assert (tmp_path / "pip-calls").read_text().splitlines()
    else:
        assert "pip 25.0" not in result.stdout
        assert not (tmp_path / "pip-calls").exists()
