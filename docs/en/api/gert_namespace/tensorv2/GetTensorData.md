# GetTensorData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:28:06.921Z pushedAt=2026-10-15T03:48:05.061Z -->

## Function

Obtains the data in the tensor and returns a read-only **TensorData** object.

## Function Prototype

```cpp
const TensorData &GetTensorData() const
```

## Parameters

None

## Return Value

Read-only tensor data reference.

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
