# GetShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:26:18.469Z pushedAt=2026-10-15T03:48:05.057Z -->

## Function

Obtains the shape of a tensor, including both the runtime and original shapes.

## Function Prototype

```cpp
const StorageShape &GetShape() const
StorageShape &GetShape()
```

## Parameters

None

## Return Value

- **const StorageShape &GetShape\(\) const**: Returns a read-only shape reference.
- **StorageShape &GetShape\(\)**: Returns a shape reference.
- For the definition of the **StorageShape** type, see [StorageShape](../storageshape/StorageShape.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {2, 1, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetShape(); // sh
```
