# GetStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:27:59.428Z pushedAt=2026-10-15T03:48:05.060Z -->

## Function

Obtains the stride in a tensor.

## Function Prototype

```cpp
const Stride &GetStride() const
```

## Parameters

None

## Return Value

Read-only reference to the tensor stride. For the definition of the **Stride** type, see [Stride](../stride/Stride.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 0};
auto stride = t.GetStride(); // str
```
