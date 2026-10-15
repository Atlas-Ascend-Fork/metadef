# MutableStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:30:19.955Z pushedAt=2026-10-15T03:48:05.065Z -->

## Function

Obtains a reference to the stride in a tensor. The stride is mutable.

## Function Prototype

```cpp
Stride &MutableStride()
```

## Parameters

None

## Return Value

Writable tensor stride reference.

For the definition of the **Stride** type, see [Stride](../stride/Stride.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Stride str({6, 3, 1});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr,nullptr, str, 0};
t.MutableStride() = Stride({6, 1, 1});
auto stride = t.GetStride(); // Stride({6, 1, 1})
```
