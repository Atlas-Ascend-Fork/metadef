# GetOptionalInputStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:40:26.056Z pushedAt=2026-10-15T03:48:05.084Z -->

## Function

Obtains the stride pointer of the corresponding optional input tensor based on the input index in the operator prototype definition.

> [!NOTE] Note
> This is a reserved API for future functionality and is not supported in the current version.

## Function Prototype

```cpp
const Stride *GetOptionalInputStride(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the optional input in the operator IR prototype definition, starting from 0.|

## Return Value

Stride pointer of the input tensor specified by **ir\_index**. For the definition of the **Stride** type, see [Stride](../stride/Stride.md).

If the input **ir\_index** is invalid, the input is not instantiated, or the tensor does not carry non-contiguous description information, a null pointer is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto option_input_stride_0 = *context->GetOptionalInputStride(0);
  ...
}
```
