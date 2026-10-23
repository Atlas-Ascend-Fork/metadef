# CreateFusionTask

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:26:18.749Z pushedAt=2026-10-15T03:48:04.698Z -->

## Function

Creates a fusion task. A fusion task refers to a task of the fusion type. Currently, a fusion task can be created by combining an AI Core task and a CCU task.

## Function Prototype

```cpp
static KernelLaunchInfo CreateFusionTask(const gert::ExeResGenerationContext *context, const std::vector<KernelLaunchInfo>& sub_tasks)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|context|Input|Input parameter of the **GenerateTask** function, which stores the basic information of the operator.|
|sub_tasks|Input|Sequence of **KernelLaunchInfo**, containing **KernelLaunchInfo** of the AI Core and CCU types.|

## Return Value

Returns the created fusion task information.

## Constraints

Currently, **sub\_tasks**  supports only the sequence combination of AI Core task + CCU task.

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // Create the sub_tasks sequence of ccuTask and aicoreTask.
  std::vector<ge::KernelLaunchInfo> sub_tasks= {CcuTask, AicoreTask};
  ge::KernelLaunchInfo fusionTask = ge::KernelLaunchInfo::CreateFusionTask(context, sub_tasks);
  ...
}
```
