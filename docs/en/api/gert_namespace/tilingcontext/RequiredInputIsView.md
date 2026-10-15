# RequiredInputIsView

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:49:25.791Z pushedAt=2026-10-15T03:48:05.100Z -->

## Function

Checks whether the corresponding required input tensor carries non-contiguous description information based on the input index in the operator IR prototype definition.

> [!NOTE] Note
> This is a reserved API for future functionality and is not supported in the current version.

## Function Prototype

```cpp
bool RequiredInputIsView(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the required input in the operator IR prototype definition, counted from 0.|

## Return Value

Returns whether the input tensor specified by **ir\_index** carries non-contiguous description information:

- **true**: The input tensor specified by **ir\_index** carries non-contiguous description information.
- **false**: The specified **ir\_index** is invalid, the input is not instantiated, or the tensor does not carry non-contiguous description information.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  bool required_input_is_view_0 = context->RequiredInputIsView(0);
  ...
}
```
