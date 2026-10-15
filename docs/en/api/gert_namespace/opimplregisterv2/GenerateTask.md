# GenerateTask

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:26:19.061Z pushedAt=2026-10-15T03:48:04.932Z -->

## Function

Generates and processes specific tasks in the **GenerateTask** stage.

## Function Prototype

```cpp
OpImplRegisterV2 &GenerateTask(OpGenTaskKernelFunc gen_task_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|gen_task_func|Input|**OpGenTaskKernelFunc** function to be registered. The **OpGenTaskKernelFunc** type is defined as follows:<br>`using OpGenTaskKernelFunc = UINT32 (*)(const ExeResGenerationContext *context, std::vector<std::vector<uint8_t>> &tasks);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, with the **OpGenTaskKernelFunc** function newly registered.

## Constraints

None
