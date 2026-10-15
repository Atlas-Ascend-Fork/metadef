# GetInputTensor

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T03:13:33.668Z pushedAt=2026-10-15T03:48:04.910Z -->

## Function

Obtains the input tensor pointer based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
const Tensor *GetInputTensor(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Returns a pointer to the input tensor. If the input **index** is invalid, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Constraints

The data address of a tensor can be obtained only when data dependency is set. If the input is not set as data-dependent, calling this API to obtain the tensor only returns the correct **shape**, **format**, and **datatype** information, but not the actual tensor data address (the obtained address is **nullptr**).

Data dependency: Generally, after the input shape is available, an operator can infer the output shape through **InferShape**. However, some operators need to depend on the specific value of an input during **InferShape**. Such operators are called "data-dependent operators", and the corresponding inputs are called "data-dependent inputs".

## Example

```cpp
ge::graphStatus InferShapeForReshape(InferShapeContext *context) {
  const gert::Shape *x_shape = context->GetInputShape(0);        // Obtain the shape of the 0th input.
  const gert::Tensor *shape_tensor = context->GetInputTensor(1); // Obtain the tensor of 1th input. Data dependency
  gert::Shape *output_shape = context->GetOutputShape(0);
  if (x_shape == nullptr || shape_tensor == nullptr || output_shape == nullptr) {
    // Defensive programming. This scenario should not occur. Print an error and return failure.
    return ge::GRAPH_FAILED;
  }
  // ...
}
```
