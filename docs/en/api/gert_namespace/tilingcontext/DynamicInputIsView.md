# DynamicInputIsView

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:33:13.449Z pushedAt=2026-10-15T03:48:05.072Z -->

## Function

Checks whether the corresponding dynamic input tensor carries non-contiguous description information based on the input index in the operator prototype definition.

> [!NOTE] note
> This is a reserved API kept for future functionality and is not supported in the current version.

## Function Prototype

```cpp
bool DynamicInputIsView(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, starting from 0.|
|relative_index|Input|Relative index after the input is instantiated. For example, if a **DYNAMIC_INPUT** is instantiated into three inputs, the valid range of **relative_index** is [0, 2].|

## Return Value

Returns whether the input tensor specified by **ir\_index** carries non-contiguous description information:

- **true**: The input tensor specified by **ir\_index** carries non-contiguous description information.
- **false**: The input **ir\_index** is invalid, the input is not instantiated, or the tensor does not carry non-contiguous description information.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  bool dynamic_input_is_view_0 = context->DynamicInputIsView(0);
  ...
}
```
