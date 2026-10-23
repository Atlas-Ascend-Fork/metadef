# GetOutputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:41:09.865Z pushedAt=2026-10-15T03:48:05.086Z -->

## Function

Obtains the corresponding output shape pointer based on the operator output index. The output index here refers to the actual index after operator instantiation, not the index in the prototype definition.

## Function Prototype

```cpp
const StorageShape *GetOutputShape(size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index, starting from 0.|

## Return Value

Specified output shape pointer. If the index is invalid, a null pointer is returned.

For the definition of the **StorageShape** type, see [StorageShape](../storageshape/StorageShape.md).

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4ConcatD(TilingContext* context) {
  auto out_shape = context->GetOutputShape(0);
  ...
}
```
