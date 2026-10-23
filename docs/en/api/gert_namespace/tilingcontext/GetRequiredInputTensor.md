# GetRequiredInputTensor

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T04:44:07.895Z pushedAt=2026-10-15T03:48:05.091Z -->

## Function

Obtains the pointer to the corresponding required input tensor based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Tensor *GetRequiredInputTensor(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the required input in the operator IR prototype definition, starting from 0.|

## Return Value

Pointer to the specified input tensor. If the input **ir\_index** is invalid, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Constraints

The data address of a tensor can be obtained only when data dependency is set. If the input is not set as data-dependent, calling this API to obtain the tensor only returns the correct **shape**, **format**, and **datatype** information in the tensor, and the actual tensor data address cannot be obtained (the obtained address is **nullptr**).

Data dependency: Generally, after the input shape is available, an operator can infer the output shape through **InferShape**. However, some operators need to depend on the specific value of an input during **InferShape**. Such operators are called "data-dependent operators", and the corresponding inputs are called "data-dependent inputs".

## Example

```cpp
ge::graphStatus InferShape4ConcatD(TilingContext* context) {
  auto in_tensor = context->GetRequiredInputTensor(0U);
  ...
}
```
