# GetDynamicInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:05:03.843Z pushedAt=2026-10-15T03:48:04.898Z -->

## Function

Obtains the corresponding dynamic input Shape pointer based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Shape *GetDynamicInputShape(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the dynamic input in the operator IR prototype definition, counting from 0.|
|relative_index|Input|Relative index of this input after instantiation. For example, if a dynamic input is instantiated into three inputs, the valid range of **relative_index** is [0, 2].|

## Return Value

Input shape pointer. If **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md).

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto shape= context->GetDynamicInputShape(1U, 0U);
  GE_ASSERT_NOTNULL(shape);
  // ...
}
```
