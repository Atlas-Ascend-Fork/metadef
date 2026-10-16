# GetAicpuBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:33:32.062Z pushedAt=2026-10-15T03:48:05.072Z -->

## Function

Obtains the number of AI CPU cores that can be scheduled as set by the user. For details about how to set it, see [SetAicpuBlockDim](SetAicpuBlockDim.md).

This parameter will be deprecated in later versions. It is recommended that you use [GetAicpuNumBlocks](GetAicpuNumBlocks.md) instead.

## Function Prototype

```cpp
uint32_t GetAicpuBlockDim() const
```

## Parameters

None

## Return Value

Number of AI CPU cores that can be scheduled as set by the user.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetAicpuBlockDim();
  // ...
}
```
