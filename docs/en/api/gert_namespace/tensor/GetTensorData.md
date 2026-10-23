# GetTensorData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:15:13.292Z pushedAt=2026-10-15T03:48:05.031Z -->

## Function

Obtains the data in a tensor and returns a read-only **TensorData** object.

## Function Prototype

```cpp
const TensorData &GetTensorData() const
```

## Parameters

None

## Return Value

Read-only reference to the tensor data.

For the definition of the **TensorData** type, see [TensorData](../tensordata/TensorData.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto a = reinterpret_cast<void *>(10);
t.MutableTensorData() = TensorData{a, nullptr}; // Set the new tensor data.
auto td = t.GetTensorData(); // TensorData{a, nullptr}
```
