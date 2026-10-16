# GetOptionalInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:14:16.953Z pushedAt=2026-10-15T03:48:04.911Z -->

## Function

Obtains the corresponding optional input shape pointer based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Shape *GetOptionalInputShape(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|

## Return Value

Returns the pointer to the input shape. If the input **ir\_index** is invalid or the input is not instantiated, a null pointer is returned.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferShapeForXXX(InferShapeContext *context) {
  auto in_shape = context->GetOptionalInputShape(2);
  // ...
}
```
