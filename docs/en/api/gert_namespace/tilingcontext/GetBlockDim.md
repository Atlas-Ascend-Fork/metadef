# GetBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:33:54.095Z pushedAt=2026-10-15T03:48:05.073Z -->

## Function

Obtains **blockDim**, that is, the number of Vector or Cube cores involved in the computation. For the detailed concept and configuration method of **blockDim**, see [SetBlockDim](SetBlockDim.md).

This parameter will be deprecated in later versions. It is recommended that you use [GetSimdNumBlocks](GetSimdNumBlocks.md).

## Function Prototype

```cpp
uint32_t GetBlockDim() const
```

## Parameters

None

## Return Value

Returns **blockDim**.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetBlockDim();
  // ...
}
```
