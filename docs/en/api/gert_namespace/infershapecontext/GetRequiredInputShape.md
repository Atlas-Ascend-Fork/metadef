# GetRequiredInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:15:42.241Z pushedAt=2026-10-15T03:48:04.913Z -->

## Function

Obtains the pointer to the required input shape based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Shape *GetRequiredInputShape(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the required input in the operator IR prototype definition, counted from 0.|

## Return Value

Returns the shape pointer of the specified input. If the input **ir\_index** is invalid, a null pointer is returned.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferShapeForXXX(InferShapeContext *context) {
  auto in_shape = context->GetRequiredInputShape(2);
  // ...
}
```
