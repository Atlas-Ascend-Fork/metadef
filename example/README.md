# example 目录说明

English: [README_en.md](README_en.md)

本目录提供 `metadef` 仓的可运行样例，用于在真实 CANN 环境中验证 GE IR 构图与 NPU 执行流程。

## 样例列表

| 样例 | 说明 |
| :--- | :--- |
| `tc_ge_irrun_open_api_0014` | 使用 GE IR Open API（`Graph`/`Tensor` 等接口）构建一个 Relu 计算图，通过 GE Session 加载并在 NPU 上执行，打印各阶段执行日志。 |

## 前提条件

- 已安装 CANN Toolkit（默认路径 `/usr/local/Ascend/cann`）。若安装路径不同，运行前请设置 `ASCEND_HOME_PATH` 环境变量指向实际安装目录。
- 已安装与 Toolkit 同路径的 CANN ops 算子包（按芯片型号选择，如 A3 环境为 `Ascend-cann-A3-ops`，910B 环境为 `Ascend-cann-910b-ops`）。样例源码包含 ops 包才提供的算子原型头文件（`opp/built-in/op_graph/inc/` 下的 `nonlinear_fuc_ops.h`、`nn_calculation_ops.h`、`array_ops.h`），Toolkit 包中不含这些头文件；仅安装 Toolkit 时编译样例会报 `fatal error: nonlinear_fuc_ops.h: No such file or directory`。ops 包与 Toolkit 从相同渠道下载（参见[快速安装](../docs/zh/quick_install.md)），安装命令如下（需与 Toolkit 安装到相同路径）：

  ```bash
  chmod +x Ascend-cann-${chip}-ops_${cann_version}_linux-${arch}.run
  ./Ascend-cann-${chip}-ops_${cann_version}_linux-${arch}.run --install --install-path=${install_path}
  ```

  其中 `${chip}` 为芯片型号（如 `A3`、`910b`）。全新搭建环境时，也可使用仓库脚本一键安装 Toolkit 与 ops 包：`bash scripts/init_env.sh --chip-type A3`。

- 已安装 NPU 驱动和固件，且当前环境可访问 NPU 设备。容器场景的设备挂载方式参见[快速安装·场景2](../docs/zh/quick_install.md)。
- 环境中已安装 Python3 及 CANN 运行所需的 Python 依赖包（GE 运行期会加载算子编译相关组件，逐层 `import` 下列 Python 包）。自行搭建的裸环境（如普通 Debian/Ubuntu 容器）通常缺少这些依赖，缺失时样例运行失败（退出码 `255`，stdout 无明显报错，plog 日志中出现 `No module named 'xxx'`），运行前请先安装：

  ```bash
  pip3 install numpy decorator sympy scipy attrs psutil
  ```

  使用 CANN 官方容器镜像时默认已具备，可跳过此步骤。

## 运行样例

```bash
cd example
bash run_example.sh
```

脚本依次执行：加载 CANN 环境变量 → 编译样例（生成 `tc_ge_irrun_open_api_0014.bin`）→ 运行样例。

## 结果判定与排查

- 成功：进程退出码为 `0`，stdout 打印各阶段 `... success` 日志（如 `GeSessionExecuteGraphWithStreamAsync success`、`Finalize acl success`）。
- 失败：进程退出码为 `255`（即 `-1`）。可按以下步骤排查：
  1. 查看 stdout 日志的最后几行，定位失败发生在哪一阶段（构图/加载/执行/资源释放）；
  2. 编译失败：确认 CANN 安装路径（`ASCEND_HOME_PATH` 或默认路径）下存在 `compiler/include`、`lib64`（以上由 Toolkit 包提供）与 `opp/built-in/op_graph/inc`（由 ops 算子包提供）等目录；若报 `nonlinear_fuc_ops.h: No such file or directory`，说明 ops 算子包未安装，请按上文『前提条件』安装后重试；
  3. 运行失败：确认驱动固件已安装、设备文件已挂载（容器场景），并查看 `~/ascend/log/` 下的 plog 日志获取详细错误码；若 plog 中出现 `No module named 'xxx'`，为 Python 依赖缺失，请按上文『前提条件』执行 `pip3 install` 安装对应包后重试。
