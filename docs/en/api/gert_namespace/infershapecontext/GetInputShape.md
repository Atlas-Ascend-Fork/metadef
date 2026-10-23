# GetInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:13:20.171Z pushedAt=2026-10-15T03:48:04.909Z -->

## Function

Obtains the input shape pointer based on the operator input index. The input index here refers to the actual index after operator instantiation, not the index in the prototype definition.

## Function Prototype

```cpp
const Shape *GetInputShape(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Input shape pointer. If the index is invalid, a null pointer is returned.

For the definition of the **Shape** type, see [Shape](../shape/Shape.md) .

## Constraints

None

## Example

```cpp
ge::graphStatus InferShapeForReshape(InferShapeContext *context) {
  const gert::Shape *x_shape = context->GetInputShape(0);        // Obtain the shape of the 0th input.
  const gert::Tensor *shape_tensor = context->GetInputTensor(1); // Obtain the tensor of the 1th input. data dependency
  gert::Shape *output_shape = context->GetOutputShape(0);
  if (x_shape == nullptr || shape_tensor == nullptr || output_shape == nullptr) {
    // Defensive programming. This scenario should not occur. Print an error and return failure.
    return ge::GRAPH_FAILED;
  }
  // ...
}
```
