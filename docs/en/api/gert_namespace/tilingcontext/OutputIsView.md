# OutputIsView

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:49:15.664Z pushedAt=2026-10-15T03:48:05.100Z -->

## Function

Checks whether the corresponding output carries non-contiguous information based on the operator output index. The output index here refers to the actual index after operator instantiation, not the index in the prototype definition.

> [!NOTE] Note
> This is a reserved API for future functionality and is not supported in the current version.

## Function Prototype

```cpp
bool OutputIsView(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index, starting from 0.|

## Return Value

Returns whether the output tensor carries non-contiguous description information:

- **true**: The output tensor carries non-contiguous description information.
- **false**: The index is invalid or the output tensor does not carry non-contiguous description information.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto output_is_view_0 = context->InputIsView(0);
  ...
}
```
