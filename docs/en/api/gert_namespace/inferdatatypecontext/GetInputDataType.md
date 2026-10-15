# GetInputDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:02:26.124Z pushedAt=2026-10-15T03:48:04.893Z -->

## Function

Obtains the data type of the corresponding input based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
ge::DataType GetInputDataType(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Input index of the operator, counted from 0.|

## Return Value

Returns the data type of the specified input.

If input **index** is invalid, **DT\_UNDEFINED** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto data_type = context->GetInputDataType(0);
  ...
}
```
