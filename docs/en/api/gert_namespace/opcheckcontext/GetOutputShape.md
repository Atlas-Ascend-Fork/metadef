# GetOutputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:22:23.727Z pushedAt=2026-10-15T03:48:04.924Z -->

## Function

Obtains the actual storage shape of the operator output tensor.

## Function Prototype

```cpp
const gert::StorageShape* GetOutputShape(int64_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index. The output index here refers to the actual index after operator instantiation, not the index in the prototype definition.|

## Return Value

Returns the [StorageShape](../storageshape/StorageShape.md) structure, which represents the storage shape of the output tensor.

## Constraints

When using it, ensure that you do not modify the returned **StorageShape** and do not attempt to release it.

## Example

```cpp
gert::StorageShape* GetOutputShape(OpCheckContext* context) {
  int64_t index = 9;
  gert::StorageShape* shape = context->GetOutputShape(index);
  ...
}
```
