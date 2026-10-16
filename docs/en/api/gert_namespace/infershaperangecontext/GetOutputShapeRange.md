# GetOutputShapeRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:19:17.544Z pushedAt=2026-10-15T03:48:04.919Z -->

## Function

Obtains the pointer to the output shape range corresponding to the operator output index. The output index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
Range<Shape> *GetOutputShapeRange(const size_t index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index, counted from 0.|

## Return Value

Pointer to the output shape range. If the index is invalid, a null pointer is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus InferShapeRangeForXXX(gert::InferShapeRangeContext *context) {
  const auto x_shape_range = context->GetInputShapeRange(0);
  if (x_shape_range == nullptr) {
    // Defensive programming ....
  }
  const auto min_shape = x_shape_range->GetMin();
  const auto max_shape = x_shape_range->GetMax();

  auto y_shape_range = context->GetOutputShapeRange(0);
  if (y_shape_range == nullptr) {
    // Defensive programming ....
  }
  if (y_shape_range->GetMin() == nullptr || y_shape_range->GetMax() == nullptr) {
    // Defensive programming ....
  }
  // shape range inference logic .....
}
```
