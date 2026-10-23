# GetOptionalInputTensor

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T03:14:38.997Z pushedAt=2026-10-15T03:48:04.911Z -->

## Function

Obtains the pointer to the corresponding optional input tensor based on the input index in the operator IR prototype definition.

## Function Prototype

```cpp
const Tensor *GetOptionalInputTensor(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the optional input in the operator IR prototype definition, counted from 0.|

## Return Value

Input tensor pointer specified by **ir\_index**. If the input **ir\_index** is invalid or the input is not instantiated, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Constraints

The data address of a tensor can be obtained only when data dependency is set. If the input is not set as data-dependent, when this API is called to obtain the tensor, only the correct **shape**, **format**, and **datatype** information can be obtained from the tensor, while the actual tensor data address cannot be obtained (the obtained address is **nullptr**).

Data dependency: Generally, after the input shape is available, an operator can infer the output shape through **InferShape**. However, some operators need to depend on the specific value of an input to perform **InferShape**. Such operators are called "data-dependent operators", and the corresponding inputs are called "data-dependent inputs".

## Example

```cpp
ge::graphStatus InferShapeForXXX(InferShapeContext *context) {
  auto in_shape = context->GetInputShape(0);
  GE_ASSERT_NOTNULL(in_shape);
  auto axes_tensor = context->GetOptionalInputTensor(1);
  ...
}
```
