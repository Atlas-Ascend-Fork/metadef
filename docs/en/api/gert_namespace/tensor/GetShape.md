# GetShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:13:41.105Z pushedAt=2026-10-15T03:48:05.027Z -->

## Function

Obtains the shape of a tensor, including the runtime shape and the original shape.

## Function Prototype

```cpp
const StorageShape &GetShape() const

StorageShape &GetShape()
```

## Parameters

None

## Return Value

- **const StorageShape &GetShape\(\) const**: Returns a read-only reference to the shape.
- **StorageShape &GetShape\(\)**: Returns a reference to the shape.

For the definition of the **StorageShape** type, see [StorageShape](../storageshape/StorageShape.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {2, 1, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetShape(); // sh
```
