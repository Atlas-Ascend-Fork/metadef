# GetSimdNumBlocks

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:44:48.176Z pushedAt=2026-10-15T03:48:05.092Z -->

## Function

Obtains the number of SIMD blocks, that is, the number of Vector or Cube cores involved in the computation. For the detailed concept and configuration method of **num\_blocks**, see [SetSimdNumBlocks](SetSimdNumBlocks.md).

## Function Prototype

```cpp
uint32_t GetSimdNumBlocks() const
```

## Parameters

None

## Return Value

Returns **num\_blocks**.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetSimdNumBlocks();
  // ...
}
```
