# CreateCcuTask

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:26:20.875Z pushedAt=2026-10-15T03:48:04.699Z -->

## Function

Creates a CCU-type task.

## Function Prototype

```cpp
static KernelLaunchInfo CreateCcuTask(const gert::ExeResGenerationContext *context, const std::vector<std::string>& groups)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|context|Input|Input parameter of the **GenerateTask** function, which stores the basic information of the operator.|
|groups|Input|Group name of the CCU task, which is the set of communicator names configured for the operator.|

## Return Value

Returns the created CCU task information.

## Constraints

None

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // Assemble ccuGroups.
  std::vector<std::string> ccuGroups = {"group_ep", "group"};
  ge::KernelLaunchInfo ccuTask = ge::KernelLaunchInfo::CreateCcuTask(context, ccuGroups);
  ...
}
```
