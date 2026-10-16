# GetInputShapeRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:18:02.114Z pushedAt=2026-10-15T03:48:04.916Z -->

## Function

Obtains the corresponding input shape range pointer based on the operator input index. The input index here refers to the actual index after operator instantiation, not the index in the prototype definition.

## Function Prototype

```cpp
const Range<Shape> *GetInputShapeRange(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Input shape range pointer. If index is invalid, a null pointer is returned.

## Constraints

None

## Example

```cpp
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetInputShapeRange(0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  output_shape_range->SetMin(const_cast<gert::Shape *>(input_shape_range->GetMin()));
  output_shape_range->SetMax(const_cast<gert::Shape *>(input_shape_range->GetMax()));
  return GRAPH_SUCCESS;
};
```
