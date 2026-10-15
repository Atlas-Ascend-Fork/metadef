# GetTilingKey

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:46:42.135Z pushedAt=2026-10-15T03:48:05.095Z -->

## Function

Obtains the tiling key.

## Function Prototype

```cpp
uint64_t GetTilingKey() const
```

## Parameters

None

## Return Value

Returns the tiling key.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_key = context->GetTilingKey();
  // ...
}
```
