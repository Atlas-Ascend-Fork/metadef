# GetDynamicInputTensorRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:17:52.739Z pushedAt=2026-10-15T03:48:04.916Z -->

## Function

Obtains the pointer to the corresponding dynamic input tensor range based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const TensorRange *GetDynamicInputTensorRange(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|
|relative_index|Input|Relative index of the instantiated input. For example, if a **DYNAMIC_INPUT** is instantiated into three inputs, the valid range of **relative_index** is [0, 2].|

## Return Value

A pointer of the **TensorRange** type, defined as follows:

```cpp
using TensorRange = Range<Tensor>;
```

If **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

## Constraints

If the input is not set as data-dependent, when calling this API to obtain the tensor range, only the correct **shape**, **format**, and **datatype** information can be obtained from the tensor, and the actual tensor data address cannot be obtained (the obtained address is **nullptr**).

## Example

```cpp
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetDynamicInputTensorRange(0U, 0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  *output_shape_range-->GetMin() = input_shape_range->GetMin()->GetStorageShape();
  *output_shape_range-->GetMax() = input_shape_range->GetMax()->GetStorageShape();
  return GRAPH_SUCCESS;
};
```
