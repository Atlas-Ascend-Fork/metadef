# GetInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:06:56.183Z pushedAt=2026-10-15T03:48:04.900Z -->

## Function

Obtains the pointer to the input shape based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
const Shape *GetInputShape(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Input shape pointer. If **index** is invalid, a null pointer is returned.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto shape= context->GetInputShape(0);        // Obtain the shape of the 0th input.
  GE_ASSERT_NOTNULL(shape);
  // ...
}
```
