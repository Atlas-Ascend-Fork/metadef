# GetOptionalInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:39:43.374Z pushedAt=2026-10-15T03:48:05.083Z -->

## Function

Obtains the shape pointer of the corresponding optional input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const StorageShape *GetOptionalInputShape(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the optional input in the operator IR prototype definition, starting from 0.|

## Return Value

Pointer to the shape of the specified input. The shape contains the original shape and the runtime shape. For the definition of the **StorageShape** type, see [StorageShape](../storageshape/StorageShape.md).

If the input **ir\_index** is invalid or the input is not instantiated, a null pointer is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4ConcatD(TilingContext* context) {
  const Shape *shape_bias = context->GetOptionalInputShape(kBatchMatMulBiasIdx);
  ...
}
```
