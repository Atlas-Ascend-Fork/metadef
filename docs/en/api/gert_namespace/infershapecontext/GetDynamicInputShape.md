# GetDynamicInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:12:57.616Z pushedAt=2026-10-15T03:48:04.908Z -->

## Function

Obtains the corresponding dynamic input shape pointer based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Shape *GetDynamicInputShape(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the dynamic input in the operator IR prototype definition, counted from 0.|
|relative_index|Input|Relative index of the instantiated input. For example, if a **DYNAMIC_INPUT** is instantiated into three inputs, the value range of **relative_index** is [0, 2].|

## Return Value

Returns the shape pointer of the specified input. If the input **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferShapeForXXX(InferShapeContext *context) {
  auto in_shape = context->GetDynamicInputShape(2, 2);
  // ...
}
```
