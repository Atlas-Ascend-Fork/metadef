# GetTilingCond

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:46:00.567Z pushedAt=2026-10-15T03:48:05.094Z -->

## Function

Obtains the tiling condition set in [GetTilingCond](GetTilingCond.md).

## Function Prototype

```cpp
int32_t GetTilingCond() const
```

## Parameters

None

## Return Value

If the return value is greater than or equal to 0, this tiling condition is a valid tiling condition.

If the return value is **-1**, this tiling condition is an invalid tiling condition.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_cond = context->GetTilingCond();
  // ...
}
```
