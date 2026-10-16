# GetBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:28:01.910Z pushedAt=2026-10-15T03:48:04.702Z -->

## Function

Obtains the **BlockDim** of the operator.

## Function Prototype

```cpp
uint32_t GetBlockDim() const
```

## Parameters

None

## Return Value

Returns the **BlockDim** value of this operator task, with a default value of **0**.

Returns **int32\_max** on exception.

## Constraints

None

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  auto block_dim = aicore_task.GetBlockDim();
  ...
}
```
