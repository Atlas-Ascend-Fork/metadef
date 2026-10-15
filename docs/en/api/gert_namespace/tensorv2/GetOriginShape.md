# GetOriginShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:25:43.140Z pushedAt=2026-10-15T03:48:05.056Z -->

## Function

Obtains the original shape of a tensor.

## Function Prototype

```cpp
const Shape &GetOriginShape() const
```

## Parameters

None

## Return Value

Read-only reference to the original shape.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {2, 1, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetOriginShape(); // 1,2,3
```
