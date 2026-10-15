# GetOptionalInputDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:02:40.773Z pushedAt=2026-10-15T03:48:04.893Z -->

## Function

Obtains the data type of the corresponding optional input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
ge::DataType GetOptionalInputDataType(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**ir_index**|Input|Index of the optional input in the operator IR prototype definition, counted from 0.|

## Return Value

Returns the data type of the specified input. If the input **ir\_index** is invalid or the input is not instantiated, **DT\_UNDEFINED** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto data_type = context->GetOptionalInputDataType(1);
  ...
}
```
