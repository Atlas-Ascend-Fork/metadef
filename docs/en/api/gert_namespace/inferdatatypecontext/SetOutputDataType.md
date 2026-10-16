# SetOutputDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:04:34.723Z pushedAt=2026-10-15T03:48:04.897Z -->

## Function

Sets the data type of a specified output based on the output index.

## Function Prototype

```cpp
ge::graphStatus SetOutputDataType(const size_t index, const ge::DataType datatype)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Output index in the operator IR prototype definition, counted from 0.|
|datatype|Input|Data type to be set for the output. For details about **DataType**, see **DataType**.|

## Return Value

Returns the status of the setting result. For status descriptions, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

If **index** is invalid, a failure value is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto ret = context->SetOutputDataType(0, ge::DataType::DT_FLOAT);
  ...
}
```
