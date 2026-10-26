# example Directory Guide

中文: [README.md](README.md)

This directory provides runnable samples of the `metadef` repository, used to verify the GE IR graph building and NPU execution flow in a real CANN environment.

## Sample List

| Sample | Description |
| :--- | :--- |
| `tc_ge_irrun_open_api_0014` | Builds a Relu compute graph with the GE IR Open API (`Graph`/`Tensor` interfaces), loads it through a GE Session, executes it on the NPU, and prints logs of each stage. |

## Prerequisites

- CANN Toolkit installed (default path `/usr/local/Ascend/cann`). If installed elsewhere, set the `ASCEND_HOME_PATH` environment variable to the actual install directory before running.
- NPU driver and firmware installed, and the NPU device accessible from the current environment. For device mounting in container scenarios, see [Quick Install · Scenario 2](../docs/en/quick_install.md).
- Python3 and the Python packages required by CANN installed (GE loads op-compilation components at runtime, which `import` the following packages layer by layer). A bare self-built environment (e.g. a plain Debian/Ubuntu container) usually lacks them; missing packages make the sample fail (exit code `255`, no obvious error on stdout, `No module named 'xxx'` in the plog logs). Install them before running:

  ```bash
  pip3 install numpy decorator sympy scipy attrs psutil
  ```

  The official CANN container image includes them by default, so this step can be skipped there.

## Run the Sample

```bash
cd example
bash run_example.sh
```

The script performs: load CANN environment -> build the sample (generates `tc_ge_irrun_open_api_0014.bin`) -> run the sample.

## Result Check and Troubleshooting

- Success: process exit code is `0`, and stdout prints `... success` logs of each stage (e.g. `GeSessionExecuteGraphWithStreamAsync success`, `Finalize acl success`).
- Failure: process exit code is `255` (i.e. `-1`). Troubleshoot as follows:
  1. Check the last lines of stdout to locate the failing stage (graph build / load / execute / finalize);
  2. Build failure: ensure the CANN install path (`ASCEND_HOME_PATH` or the default) contains `compiler/include`, `lib64`, `opp/built-in/op_graph/inc`, etc.;
  3. Run failure: ensure the driver and firmware are installed and device files are mounted (container scenarios), and check the plog logs under `~/ascend/log/` for detailed error codes; if the plog shows `No module named 'xxx'`, Python packages are missing — install them with `pip3 install` as described in "Prerequisites" above and retry.
