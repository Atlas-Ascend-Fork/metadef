# GetDynamicInputDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:01:44.590Z pushedAt=2026-10-15T03:48:04.892Z -->

## Function

Obtains the data type of the corresponding dynamic input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
ge::DataType GetDynamicInputDataType(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the dynamic input in the operator IR prototype definition, counted from 0.|
|relative_index|Input|Relative index of the instantiated input. For example, if a **DYNAMIC_INPUT** is instantiated into three inputs, the value range of **relative_index** is [0,2].|

## Return Value

Returns the data type of the specified input. If the input **ir\_index** or **relative\_index** is invalid, returns **DT\_UNDEFINED**.

## Constraints

None

## Example

```cpp
ge::graphStatus InferDataTypeForXXX(InferDataTypeContext *context) {
  auto data_type = context->GetDynamicInputDataType(1, 2);
  ...
}
```
