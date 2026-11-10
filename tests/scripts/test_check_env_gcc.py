# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.

"""Check compiler version handling through the environment script."""

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
    "full,expected",
    [
        ("7.2.0", "[ERROR]"),
        ("7.3.0", "[PASS]"),
        ("7.5.0", "[PASS]"),
        ("8.1.0", "[PASS]"),
    ],
)
def test_gcc_minor_version_is_used(tmp_path, full, expected):
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
    gcc = path / "gcc"
    gcc.write_text(
        '#!/bin/sh\nif [ "$1" = "-dumpfullversion" ]; then echo '
        + full
        + '; elif [ "$1" = "-dumpversion" ]; then echo '
        + full.split(".")[0]
        + "; fi\n",
        encoding="utf-8",
    )
    gcc.chmod(0o755)
    (path / "g++").symlink_to(gcc)
    result = subprocess.run(
        ["/bin/bash", str(SCRIPT)],
        env={**os.environ, "PATH": str(path), "LC_ALL": "C.UTF-8"},
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    plain = re.sub(r"\x1b\[[0-9;]*m", "", result.stdout)
    assert any(
        expected in line and ("GCC " in line or "GCC 版本" in line)
        for line in plain.splitlines()
    )
    assert any(
        "[PASS]" in line and f"G++ {full}" in line for line in plain.splitlines()
    )


def test_older_gcc_without_fullversion_option_is_rejected(tmp_path):
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
    gcc = path / "gcc"
    gcc.write_text(
        '#!/bin/sh\nif [ "$1" = "-dumpversion" ]; then echo 6.5.0; else exit 1; fi\n',
        encoding="utf-8",
    )
    gcc.chmod(0o755)
    (path / "g++").symlink_to(gcc)
    result = subprocess.run(
        ["/bin/bash", str(SCRIPT)],
        env={**os.environ, "PATH": str(path), "LC_ALL": "C.UTF-8"},
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )
    plain = re.sub(r"\x1b\[[0-9;]*m", "", result.stdout)
    assert any("[ERROR]" in line and "6.5.0" in line for line in plain.splitlines())
    assert any("[PASS]" in line and "G++ 6.5.0" in line for line in plain.splitlines())
