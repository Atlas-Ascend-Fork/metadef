# GetDynamicInputTensor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:05:16.471Z pushedAt=2026-10-15T03:48:04.898Z -->

## Function

Obtains the corresponding dynamic input tensor pointer based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Tensor *GetDynamicInputTensor(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**ir_index**|Input|Index of the input in the operator IR prototype definition, counted from 0.|
|**relative_index**|Input|Relative index of the instantiated input. For example, if a dynamic input is instantiated into three inputs, the valid range of **relative_index** is [0, 2].|

## Return Value

Input **Tensor** pointer. If **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto axes_tensor_10 = context->GetDynamicInputTensor(1U, 0U);
  auto axes_tensor_11 = context->GetDynamicInputTensor(1U, 1U);
  ...
}
```
