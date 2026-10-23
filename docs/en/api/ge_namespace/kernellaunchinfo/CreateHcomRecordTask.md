# CreateHcomRecordTask

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:26:52.150Z pushedAt=2026-10-15T03:48:04.700Z -->

## Function

Creates a Record task, which is used to wake up the Wait task that has the same **group\_name** on other streams.

## Function Prototype

```cpp
static KernelLaunchInfo CreateHcomRecordTask(const gert::ExeResGenerationContext *context, const char *group_name = "group")
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|context|Input|Input parameter of the **GenerateTask** function, which stores the basic information of the operator.|
|group_name|Input|Group name of the Record task, defaulting to **group**, which is used to pair with the Wait task.|

## Return Value

Returns the created Record task information.

## Constraints

**group\_name** must be consistent with the attribute defined in the operator prototype. For example, if an MC2 operator defines an attribute **group\_ep**, you can use **group\_name** to create a Record task and a Wait task for **group\_ep**.

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // Create a RecordTask.
  auto record_task = KernelLaunchInfo::CreateHcomRecordTask(context);
  // Set the stream information.
  record_task.SetStreamId(stream_id);
  tasks.insert(tasks.begin() + aicore_index, record_task.Serialize());
  aicore_index++;
  ...
}
```
