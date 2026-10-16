# GetDynamicInputOffset

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:35:20.309Z pushedAt=2026-10-15T03:48:05.076Z -->

## Function

Obtains the offset of the corresponding dynamic input tensor based on the input index in the operator prototype definition.

> [!NOTE] Note
> This is a reserved API kept for future functionality and is not supported in the current version.

## Function Prototype

```cpp
int64_t GetDynamicInputOffset(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|
|relative_index|Input|Relative index after this input is instantiated. For example, if a **DYNAMIC_INPUT** is instantiated into three inputs, the valid range of **relative_index** is [0, 2].|

## Return Value

Offset information of the specified input tensor. If **ir\_index** or **relative\_index** is invalid or the tensor does not carry non-contiguous description information, **-1** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto dynamic_input_offset_0 = context->GetDynamicInputOffset(0);
  ...
}
```
