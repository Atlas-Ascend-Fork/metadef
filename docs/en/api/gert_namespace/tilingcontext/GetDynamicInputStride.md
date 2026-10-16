# GetDynamicInputStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:36:06.855Z pushedAt=2026-10-15T03:48:05.077Z -->

## Function

Obtains the stride pointer of the corresponding dynamic input Tensor based on the input index in the operator prototype definition.

> [!NOTE]
> This is a reserved interface for future functionality and is not supported in the current version.

## Function Prototype

```cpp
const Stride *GetDynamicInputStride(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|
|relative_index|Input|Relative index of the instantiated input. For example, if a **DYNAMIC_INPUT** is instantiated into three inputs, the valid range of **relative_index** is [0, 2].|

## Return Value

Stride pointer of the specified input tensor. If **ir\_index** or **relative\_index** is invalid or the tensor does not carry non-contiguous description information, a null pointer is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto dynamic_input_stride_0 = *context->GetDynamicInputStride(0);
  ...
}
```
