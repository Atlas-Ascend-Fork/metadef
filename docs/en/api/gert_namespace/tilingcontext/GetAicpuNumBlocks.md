# GetAicpuNumBlocks

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:33:44.536Z pushedAt=2026-10-15T03:48:05.073Z -->

## Function

Obtains the number of AI CPU cores that can be scheduled as set by the user. For details about how to set it, see [SetAicpuNumBlocks](SetAicpuNumBlocks.md).

## Function Prototype

```cpp
uint32_t GetAicpuNumBlocks() const
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
  auto block_dim = context->GetAicpuNumBlocks();
  // ...
}
```
