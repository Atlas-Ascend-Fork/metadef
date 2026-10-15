# GetDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:11:46.146Z pushedAt=2026-10-15T03:48:05.023Z -->

## Function

Obtains the data type of a tensor.

## Function Prototype

```cpp
ge::DataType GetDataType() const
```

## Parameters

None

## Return Value

Returns the data type in the tensor.

For the definition of **ge::DataType**, see [DataType](../../ge_namespace/DataType.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto dt = t.GetDataType(); //  ge::DT_FLOAT
```
