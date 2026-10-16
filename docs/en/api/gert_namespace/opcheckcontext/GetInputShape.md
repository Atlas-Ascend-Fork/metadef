# GetInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:21:59.590Z pushedAt=2026-10-15T03:48:04.922Z -->

## Function

Obtains the actual storage shape of an operator's input tensor.

## Function Prototype

```cpp
const gert::StorageShape* GetInputShape(int64_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Input index of the operator. This input index refers to the actual index after the operator is instantiated, not the index in the prototype definition.|

## Return Value

Returns a [StorageShape](../storageshape/StorageShape.md) structure, which represents the storage shape of the input tensor.

## Constraints

When using it, ensure that you do not modify the returned **StorageShape** and do not attempt to release it.

## Example

```cpp
gert::StorageShape* GetInputShape(OpCheckContext* context) {
  int64_t index = 9;
  gert::StorageShape* shape = context->GetInputShape(index);
  ...
}
```
