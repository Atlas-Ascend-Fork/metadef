# GetRequiredInputDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:03:22.261Z pushedAt=2026-10-15T03:48:04.894Z -->

## Function

Obtains the data type of the corresponding required input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
ge::DataType GetRequiredInputDataType(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the required input in the operator IR prototype definition, counted from 0.|

## Return Value

Returns the data type of the specified input. If the input **ir\_index** is invalid, **DT\_UNDEFINED** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto data_type = context->GetRequiredInputDataType(1);
  ...
}
```
