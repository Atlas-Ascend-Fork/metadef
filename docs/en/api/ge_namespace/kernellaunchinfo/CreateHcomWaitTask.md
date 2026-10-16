# CreateHcomWaitTask

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:27:07.819Z pushedAt=2026-10-15T03:48:04.700Z -->

## Function

Creates a Wait task that blocks a stream. The blocking is released when a Record task with the same **group\_name** is executed.

## Function Prototype

```cpp
static KernelLaunchInfo CreateHcomWaitTask(const gert::ExeResGenerationContext *context, const char *group_name = "group")
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|context|Input|Input parameter of the **GenerateTask** function, which stores the basic information of the operator.|
|group_name|Input|Group name of the Wait task, defaulting to **group**, used to pair with the Record task.|

## Return Value

Returns the created Wait task information.

## Constraints

**group\_name** must be consistent with the attribute defined in the operator prototype. For example, if an MC2 operator defines an attribute **group\_ep**, you can use **group\_ep** as **group\_name** to create a Record task and a Wait task.

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // Create a WaitTask.
  auto wait_task = KernelLaunchInfo::CreateHcomWaitTask(context);
  wait_task.SetStreamId(attach_stream_id);
  tasks.insert(tasks.begin() + aicore_index, wait_task.Serialize());
  aicore_index++;
  ...
}
```
