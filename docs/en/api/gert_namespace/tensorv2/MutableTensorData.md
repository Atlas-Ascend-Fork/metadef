# MutableTensorData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:30:26.166Z pushedAt=2026-10-15T03:48:05.065Z -->

## Function

Obtains the data in a tensor.

## Function Prototype

```cpp
TensorData &MutableTensorData()
```

## Parameters

None

## Return Value

Writable tensor data reference.

For the definition of the **TensorData** type, see [TensorData](../tensordata/TensorData.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto a = reinterpret_cast<void *>(10);
t.MutableTensorData() = TensorData{a, nullptr}; // Set the new tensor data.
auto addr = t.GetTensorData().GetAddr(); // 10
```
