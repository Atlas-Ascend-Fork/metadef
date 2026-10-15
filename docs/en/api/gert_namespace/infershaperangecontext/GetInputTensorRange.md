# GetInputTensorRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:18:21.398Z pushedAt=2026-10-15T03:48:04.918Z -->

## Function

Obtains the pointer to the input tensor range based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
const TensorRange *GetInputTensorRange(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Pointer of the **TensorRange** type, defined as follows:

```cpp
using TensorRange = Range<Tensor>;
```

If index is invalid, a null pointer is returned.

## Constraints

If the input is not set as data-dependent, calling this API to obtain the tensor range only retrieves the correct **shape**, **format**, and **datatype** information from the tensor, but cannot obtain the actual tensor data address (the obtained address is **nullptr**).

## Example

```cpp
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_tensor_range = context->GetInputTensorRange(0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  auto input_tensor = input_tensor_range->GetMax();
  auto shape_data = input_tensor->GetData<int64_t>();
  auto shape_size = input_tensor->GetShapeSize();
  // ... output_shape_range inference logic.
  return GRAPH_SUCCESS;
};
```
