# OptionalInputIsView

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:48:51.004Z pushedAt=2026-10-15T03:48:05.099Z -->

## Function

Checks whether the corresponding optional input tensor carries non-contiguous description information based on the input index in the operator prototype definition.

> [!NOTE] Note
> This is a reserved API for future functionality and is not supported in the current version.

## Function Prototype

```cpp
bool OptionalInputIsView(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the optional input in the operator IR prototype definition, counted from 0.|

## Return Value

Returns whether the input tensor at the specified **ir\_index** carries non-contiguous description information:

- **true**: The input tensor at the specified **ir\_index** carries non-contiguous description information.
- **false**: The input **ir\_index** is invalid, the input is not instantiated, or the tensor does not carry non-contiguous description information.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto option_input_is_view_0 = context->OptionalInputIsView(0);
  ...
}
```
