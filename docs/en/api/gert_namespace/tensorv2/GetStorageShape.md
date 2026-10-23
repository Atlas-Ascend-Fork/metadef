# GetStorageShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:27:41.618Z pushedAt=2026-10-15T03:48:05.059Z -->

## Function

Obtains the **StorageShape** of a runtime tensor. This shape object is read-only. The differences between **StorageShape** and [Originshape](../tensor/GetOriginShape.md) are as follows: **Originshape** is the shape of the tensor when it is initially created, while **StorageShape** is the shape of the underlying storage that holds the tensor data. To adapt to the underlying hardware at runtime, the **StorageShape** of a tensor may differ from its **Originshape**.

## Function Prototype

```cpp
const Shape &GetStorageShape() const
```

## Parameters

None

## Return Value

Read-only runtime shape reference.

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {2, 1, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.GetStorageShape(); // 2,1,3
```
