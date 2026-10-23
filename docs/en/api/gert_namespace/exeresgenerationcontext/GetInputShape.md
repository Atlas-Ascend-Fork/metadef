# GetInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:46:44.071Z pushedAt=2026-10-15T03:48:04.864Z -->

## Function

Obtains the actual storage shape of an operator input tensor.

## Function Prototype

```cpp
const gert::StorageShape* GetInputShape(int64_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index. This input index refers to the actual index after operator instantiation, not the index in the prototype definition.|

## Return Value

Returns the [StorageShape](../storageshape/StorageShape.md) structure, which represents the storage shape of the input tensor.

## Constraints

When using it, ensure that you do not modify or attempt to release the returned **StorageShape**.

## Example

```cpp
gert::StorageShape* GetInputShape(ExeResGenerationContext* context) {
  int64_t index = 9;
  gert::StorageShape* shape = context->GetInputShape(index);
  ...
}
```
