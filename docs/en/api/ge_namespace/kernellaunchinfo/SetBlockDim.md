# SetBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:32:08.875Z pushedAt=2026-10-15T03:48:04.708Z -->

## Function

Sets the operator **BlockDim**.

## Function Prototype

```cpp
graphStatus SetBlockDim(uint32_t block_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|block_dim|Input|Operator **BlockDim**.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../ge-graphStatus.md).

## Constraints

None

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  aicpu_task.SetBlockDim(4);
  ...
}
```
