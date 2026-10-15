# GetInputTensor

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T04:38:44.959Z pushedAt=2026-10-15T03:48:05.082Z -->

## Function

Obtains the corresponding input tensor pointer based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
const Tensor *GetInputTensor(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Pointer to the specified input tensor. If the input index is invalid, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Constraints

The data address of a tensor can be obtained only when data dependency is set. If the input is not set as data-dependent, calling this API to obtain the tensor only returns the correct **shape**, **format**, and **datatype** information, but not the actual tensor data address (the obtained address is **nullptr**).

Data dependency: Generally, after the input shape is available, an operator can infer the output shape through **InferShape**. However, some operators need to depend on the specific value of an input to perform **InferShape**. Such operators are called "data-dependent operators", and the corresponding inputs are called "data-dependent inputs".

## Example

```cpp
ge::graphStatus Tiling4ReduceCommon(TilingContext* context) {
  auto in_shape = context->GetInputShape(0);
  GE_ASSERT_NOTNULL(in_shape);
  auto axes_tensor = context->GetInputTensor(1);
  ...
}
```
