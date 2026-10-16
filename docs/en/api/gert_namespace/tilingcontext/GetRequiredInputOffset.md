# GetRequiredInputOffset

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:43:17.000Z pushedAt=2026-10-15T03:48:05.089Z -->

## Function

Obtains the offset of the corresponding required input tensor based on the input index in the operator prototype definition.

> [!NOTE] Note
> This is a reserved API for future functionality and is not supported in the current version.

## Function Prototype

```cpp
int64_t GetRequiredInputOffset(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the required input in the operator IR prototype definition, starting from 0.|

## Return Value

Offset of the specified input tensor. If the input **ir\_index** is invalid or the tensor does not carry non-contiguous description information, **-1** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto required_input_offset_0 = context->GetRequiredInputOffset(0);
  ...
}
```
