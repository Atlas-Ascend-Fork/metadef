# GetOptionalInputShapeRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:18:45.041Z pushedAt=2026-10-15T03:48:04.917Z -->

## Function

Obtains the pointer to the optional input shape range corresponding to the input index defined in the operator prototype.

## Function Prototype

```cpp
const Range<Shape> *GetOptionalInputShapeRange(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index defined in the operator IR prototype, counted from 0.|

## Return Value

Returns the shape range pointer. If **ir\_index** is invalid or the **input** is not instantiated, a null pointer is returned.

## Constraints

None

## Example

```cpp
const auto infer_shape_range_func = [](gert::InferShapeRangeContext *context) -> graphStatus {
  auto input_shape_range = context->GetOptionalInputShapeRange(0U);
  auto output_shape_range = context->GetOutputShapeRange(0U);
  output_shape_range->SetMin(const_cast<gert::Shape *>(input_shape_range->GetMin()));
  output_shape_range->SetMax(const_cast<gert::Shape *>(input_shape_range->GetMax()));
  return GRAPH_SUCCESS;
};
```
