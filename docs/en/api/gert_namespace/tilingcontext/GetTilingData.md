# GetTilingData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:46:27.232Z pushedAt=2026-10-15T03:48:05.095Z -->

## Function

Obtains a typed tiling data pointer.

## Function Prototype

```cpp
template<typename T> auto GetTilingData() -> T*
```

## Parameters

|Parameter|Description|
|--|--|
|T|Tiling data type. **sizeof(T)** must not exceed the maximum tiling data length specified in the compilation result.|

## Return Value

Tiling data pointer. A null pointer is returned on failure.

## Constraints

**sizeof\(T\)** must not be greater than the maximum tiling data length specified in the compilation result.

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto tiling_data = context->GetTilingData<int64_t>();
  // ...
}
```
