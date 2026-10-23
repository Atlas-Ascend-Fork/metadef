# example 目录说明

English: [README_en.md](README_en.md)

本目录提供 `metadef` 仓的可运行样例，用于在真实 CANN 环境中验证 GE IR 构图与 NPU 执行流程。

## 样例列表

| 样例 | 说明 |
| :--- | :--- |
| `tc_ge_irrun_open_api_0014` | 使用 GE IR Open API（`Graph`/`Tensor` 等接口）构建一个 Relu 计算图，通过 GE Session 加载并在 NPU 上执行，打印各阶段执行日志。 |

## 前提条件

- 已安装 CANN Toolkit（默认路径 `/usr/local/Ascend/cann`）。若安装路径不同，运行前请设置 `ASCEND_HOME_PATH` 环境变量指向实际安装目录。
- 已安装 NPU 驱动和固件，且当前环境可访问 NPU 设备。容器场景的设备挂载方式参见[快速安装·场景2](../docs/zh/quick_install.md)。
- 环境中已安装 Python3 及 CANN 运行所需的 Python 依赖包（GE 运行期会加载算子编译相关组件，依赖 Python 环境）。使用 CANN 官方容器镜像时默认已具备。

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
  2. 编译失败：确认 CANN 安装路径（`ASCEND_HOME_PATH` 或默认路径）下存在 `compiler/include`、`lib64`、`opp/built-in/op_graph/inc` 等目录；
  3. 运行失败：确认驱动固件已安装、设备文件已挂载（容器场景），并查看 `~/ascend/log/` 下的 plog 日志获取详细错误码。
