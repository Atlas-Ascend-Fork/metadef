# GetOffset

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:25:01.846Z pushedAt=2026-10-15T03:48:05.054Z -->

## Function

Obtains the offset in a tensor.

## Function Prototype

```cpp
int64_t GetOffset() const
```

## Parameters

None

## Return Value

Offset in a tensor.

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 10};
auto offset = t.GetOffset(); // 10
```
