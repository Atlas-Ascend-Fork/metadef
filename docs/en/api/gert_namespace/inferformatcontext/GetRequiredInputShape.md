# GetRequiredInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:10:00.574Z pushedAt=2026-10-15T03:48:04.904Z -->

## Function

Obtains the required input Shape pointer corresponding to the input index in the operator prototype definition.

## Function Prototype

```cpp
const Shape *GetRequiredInputShape(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index in the IR prototype definition, counting from 0.|

## Return Value

Input shape pointer. If **ir\_index** is invalid, a null pointer is returned.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md).

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto shape= context->GetRequiredInputShape(0);        // Obtain the shape of the 0th input.
  GE_ASSERT_NOTNULL(shape);
  // ...
}
```
