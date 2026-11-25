# CreateFusionTask

## 函数功能

根据子任务序列创建Fusion Task；子任务可以是AI Core和/或CCU Task。

## 函数原型

```cpp
static KernelLaunchInfo CreateFusionTask(const gert::ExeResGenerationContext *context, const std::vector<KernelLaunchInfo>& sub_tasks)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|context|输入|GenerateTask函数的入参，保存了算子的基础信息。|
|sub_tasks|输入|KernelLaunchInfo序列，包含AI Core和CCU类型的KernelLaunchInfo。|

## 返回值说明

返回创建出来的Fusion Task信息。

## 约束说明

每个 sub_tasks 项必须是 AI Core 或 CCU Task。序列可以包含多个同类子任务，序列化后的顺序与输入顺序一致。

## 调用示例

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  //创建ccuTask和aicoreTask的sub_tasks序列
  std::vector<ge::KernelLaunchInfo> sub_tasks= {CcuTask, AicoreTask};
  ge::KernelLaunchInfo fusionTask = ge::KernelLaunchInfo::CreateFusionTask(context, sub_tasks);
  ...
}
```
