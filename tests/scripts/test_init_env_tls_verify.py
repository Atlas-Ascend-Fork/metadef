# Copyright (c) 2026 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.

"""TLS certificate verification must stay on unless explicitly opted out."""

import os
import subprocess
from pathlib import Path

SCRIPT = Path(
    os.environ.get("INIT_ENV_SCRIPT", Path(__file__).parents[2] / "scripts/init_env.sh")
)

MAIN_HARNESS = r"""
source "$CASE_ROOT/functions.sh"
install_system_deps() { :; }
main --skip-cann $EXTRA_ARGS >/dev/null 2>&1
printf '[%s]' "${WGET_OPTS[@]}"
"""

WGET_ARGS_HARNESS = r"""
source "$CASE_ROOT/functions.sh"
wget() {
    printf '[%s]' "$@" >> "$CASE_ROOT/wget_args"
    echo >> "$CASE_ROOT/wget_args"
    return 1
}
get_cann_url >/dev/null 2>&1 || true
WGET_OPTS+=(--no-check-certificate)
get_cann_url >/dev/null 2>&1 || true
"""


def _write_functions(tmp_path) -> None:
    source = SCRIPT.read_text(encoding="utf-8")
    assert source.rstrip().endswith('main "$@"')
    (tmp_path / "functions.sh").write_text(
        source.rsplit('main "$@"', 1)[0], encoding="utf-8"
    )


def _run(tmp_path, harness: str, extra_args: str = ""):
    return subprocess.run(
        ["/bin/bash", "-c", harness],
        env={**os.environ, "CASE_ROOT": str(tmp_path), "EXTRA_ARGS": extra_args},
        capture_output=True,
        text=True,
        encoding="utf-8",
        timeout=30,
    )


def test_tls_verification_enabled_by_default(tmp_path):
    _write_functions(tmp_path)
    result = _run(tmp_path, MAIN_HARNESS)
    assert result.returncode == 0, result.stderr
    assert result.stdout == "[]"


def test_no_check_certificate_is_opt_in(tmp_path):
    _write_functions(tmp_path)
    result = _run(tmp_path, MAIN_HARNESS, "--no-check-certificate")
    assert result.returncode == 0, result.stderr
    assert result.stdout == "[--no-check-certificate]"


def test_wget_calls_use_configured_opts(tmp_path):
    _write_functions(tmp_path)
    result = _run(tmp_path, WGET_ARGS_HARNESS)
    assert result.returncode == 0, result.stderr
    lines = (tmp_path / "wget_args").read_text(encoding="utf-8").splitlines()
    assert len(lines) == 2
    assert "--no-check-certificate" not in lines[0]
    assert "--no-check-certificate" in lines[1]
