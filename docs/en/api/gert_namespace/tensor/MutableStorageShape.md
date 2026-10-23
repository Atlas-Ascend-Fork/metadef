# MutableStorageShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:16:51.031Z pushedAt=2026-10-15T03:48:05.035Z -->

## Function

Obtains the shape of a runtime tensor. This shape object is mutable.

## Function Prototype

```cpp
Shape &MutableStorageShape()
```

## Parameters

None

## Return Value

Reference to the runtime shape.

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {2, 1, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto shape = t.MutableStorageShape(); // 2,1,3
```
