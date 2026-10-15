# InputIsView

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:48:03.980Z pushedAt=2026-10-15T03:48:05.098Z -->

## Function

Checks whether the corresponding input carries non-contiguous information based on the operator input index. The input index here refers to the actual index after operator instantiation, not the index in the prototype definition.

## Function Prototype

```cpp
bool InputIsView(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Returns whether the input tensor carries non-contiguous description information:

- **true**: The input tensor carries non-contiguous description information.
- **false**: The index is invalid or the input tensor does not carry non-contiguous description information.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  bool input_is_view_0 = context->InputIsView(0);
  ...
}
```
