# GetRawTilingData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:42:53.784Z pushedAt=2026-10-15T03:48:05.088Z -->

## Function

Obtains the untyped tiling data pointer.

## Function Prototype

```cpp
TilingData *GetRawTilingData()
```

## Parameters

None

## Return Value

Tiling data pointer. A null pointer is returned on failure.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_data = context->GetRawTilingData();
  // ...
}
```
