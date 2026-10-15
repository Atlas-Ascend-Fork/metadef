# GetOutputStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:41:48.798Z pushedAt=2026-10-15T03:48:05.087Z -->

## Function

Obtains the corresponding output Stride pointer based on the operator output index. The output index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

> [!NOTE]NOTE
> This interface is reserved for future functionality and is not supported in the current version.

## Function Prototype

```cpp
const Stride *GetOutputStride(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index, starting from 0.|

## Return Value

Specified input stride pointer. For the definition of the **Stride** type, see [Stride](../stride/Stride.md).

If the index is invalid or the tensor does not carry non-contiguous description information, a null pointer is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto output_stride_0 = *context->GetOutputStride(0);
  ...
}
```
