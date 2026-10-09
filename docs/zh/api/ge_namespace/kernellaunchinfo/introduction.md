# 简介

KernelLaunchInfo类为开发者提供创建和管理下发给Device的任务接口，允许开发者设置或者获取当前待下发Device任务的相关Launch信息。

本类可以支持用户创建新的Launch任务或者修改框架已经生成好的Launch任务。

## 需要包含的头文件

```cpp
#include <graph/kernel_launch_info.h>
```

该头文件由GE（Graph Engine）组件随CANN Toolkit安装到`${INSTALL_DIR}/include/graph/`，不属于metadef仓库源码中的头文件。

## Public成员函数

```cpp
static KernelLaunchInfo LoadFromData(const gert::ExeResGenerationContext *context, const std::vector<uint8_t> &data)
static KernelLaunchInfo CreateAicpuKfcTask(const gert::ExeResGenerationContext *context, const char *so_name, const char *kernel_name)
static KernelLaunchInfo CreateHcomRecordTask(const gert::ExeResGenerationContext *context, const char *group_name = "group")
static KernelLaunchInfo CreateHcomWaitTask(const gert::ExeResGenerationContext *context, const char *group_name = "group")
static KernelLaunchInfo CreateFusionTask(const gert::ExeResGenerationContext *context, const std::vector<KernelLaunchInfo> &sub_tasks)
static KernelLaunchInfo CreateCcuTask(const gert::ExeResGenerationContext *context, const std::vector<std::string> &groups)
std::vector<uint8_t> Serialize()
uint32_t GetStreamId() const
void SetStreamId(uint32_t stream_id)
uint32_t GetBlockDim() const
graphStatus SetBlockDim(uint32_t block_dim)
const char *GetArgsFormat() const
graphStatus SetArgsFormat(const char *args_format)
const char *GetSoName() const
const char *GetKernelName() const
```
