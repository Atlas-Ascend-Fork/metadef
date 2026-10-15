# GetInputStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:38:17.859Z pushedAt=2026-10-15T03:48:05.081Z -->

## Function

Obtains the corresponding input stride pointer based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

> [!NOTE] Note
> This is a reserved API kept for future functionality, and is not supported in the current version.

## Function Prototype

```cpp
const Stride *GetInputStride(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Pointer to the specified input stride. For the definition of the **Stride** type, see [Stride](../stride/Stride.md).

If the index is invalid or the tensor does not carry non-contiguous description information, a null pointer is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto input_stride_0 = *context->GetInputStride(0);
  ...
}
```
