# CreateAicpuKfcTask

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:25:53.251Z pushedAt=2026-10-15T03:48:04.698Z -->

## Function

Creates a KFC task for the AI CPU.

## Function Prototype

```cpp
static KernelLaunchInfo CreateAicpuKfcTask(const gert::ExeResGenerationContext *context, const char *so_name, const char *kernel_name)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|context|Input|Input parameter of the GenerateTask function, which stores the basic information of the operator.|
|so_name|Input|Name of the so package of the AI CPU operator.|
|kernel_name|Input|Name of the entry function of the AI CPU operator.|

## Return Value

Returns the created AI CPU KFC task information.

## Constraints

None

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // Create the AI CPU task.
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  // Obtain the attach stream.
  auto stream_infos = context->GetAttachedStreamInfos();
  GE_ASSERT_TRUE(!stream_infos.empty());
  const int64_t attach_stream_id = stream_infos[0].stream_id;
  // Add information to the AI CPU KFC task.
  aicpu_task->SetStreamId(attach_stream_id);
  ...
}
```
