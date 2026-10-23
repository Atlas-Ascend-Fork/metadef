# GetOutputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:47:51.125Z pushedAt=2026-10-15T03:48:04.866Z -->

## Function

Obtains the actual storage shape of an operator output tensor.

## Function Prototype

```cpp
const gert::StorageShape* GetOutputShape(int64_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index. The output index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.|

## Return Value

Returns a **StorageShape** structure, which represents the storage shape of the output shape.

## Constraints

When using it, ensure that you do not modify the returned **StorageShape** or attempt to release it.

## Example

```cpp
gert::StorageShape* GetOutputShape(ExeResGenerationContext* context) {
  int64_t index = 9;
  gert::StorageShape* shape = context->GetOutputShape(index);
  ...
}
```
