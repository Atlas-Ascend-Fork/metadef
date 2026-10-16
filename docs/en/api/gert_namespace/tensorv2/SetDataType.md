# SetDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:30:59.493Z pushedAt=2026-10-15T03:48:05.066Z -->

## Function

Sets the data type of a tensor.

## Function Prototype

```cpp
void SetDataType(const ge::DataType data_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data_type|Input|Data type to be set for the tensor. For the definition of **ge::DataType**, see **DataType**.|

## Return Value

None

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetDataType(ge::DT_DOUBLE);
```
