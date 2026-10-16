# GetRequiredInputShapeRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:19:55.497Z pushedAt=2026-10-15T03:48:04.920Z -->

## Function

Obtains the pointer to the shape range of the corresponding required input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Range<Shape> *GetRequiredInputShapeRange(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the required input in the operator IR prototype definition, counted from 0.|

## Return Value

Shape range pointer. If **ir\_index** is invalid, a null pointer is returned.

## Constraints

None

## Example

```cpp
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetRequiredInputShapeRange(0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  output_shape_range->SetMin(const_cast<gert::Shape *>(input_shape_range->GetMin()));
  output_shape_range->SetMax(const_cast<gert::Shape *>(input_shape_range->GetMax()));
  return GRAPH_SUCCESS;
};
```
