# GetOutputDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:02:58.428Z pushedAt=2026-10-15T03:48:04.894Z -->

## Function

Obtains the data type of the corresponding output based on the operator output index. The output index here refers to the actual index after operator instantiation, not the index in the prototype definition.

## Function Prototype

```cpp
ge::DataType GetOutputDataType(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index, counted from 0.|

## Return Value

Returns the data type of the specified output. If **index** is invalid, **DT\_UNDEFINED** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto data_type = context->GetOutputDataType(0);
  ...
}
```
