# GetDynamicInputTensor

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T04:36:35.003Z pushedAt=2026-10-15T03:48:05.078Z -->

## Function

Obtains the corresponding dynamic input Tensor pointer based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Tensor *GetDynamicInputTensor(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|
|relative_index|Input|Relative index after the input is instantiated. For example, if a DYNAMIC_INPUT is instantiated into three inputs, the valid range of relative_index is [0,2].|

## Return Value

Pointer to the specified input tensor. If **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Constraints

The data address of a tensor can be obtained only when data dependency is set. If the input is not set as data-dependent, calling this API to obtain the tensor only returns the correct shape, format, and datatype information, but not the actual tensor data address (the obtained address is **nullptr**).

Data dependency: Generally, after the input shape is available, an operator can infer the output shape through **InferShape**. However, some operators need to depend on the specific value of an input during **InferShape**. Such operators are called "data-dependent operators", and the corresponding inputs are called "data-dependent inputs".

## Example

```cpp
ge::graphStatus Tiling4ReduceCommon(TilingContext* context) {
  auto in_shape = context->GetInputShape(0);
  GE_ASSERT_NOTNULL(in_shape);
  auto axes_tensor_10 = context->GetDynamicInputTensor(1, 0);
  auto axes_tensor_11 = context->GetDynamicInputTensor(1, 1);
  ...
}
```
