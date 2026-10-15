# GetOutputOffset

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:41:04.697Z pushedAt=2026-10-15T03:48:05.085Z -->

## Function

Obtains the corresponding output offset based on the operator output index. The output index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

> [!NOTE] Note
> This is a reserved API for future functionality and is not supported in the current version.

## Function Prototype

```cpp
int64_t GetOutputOffset(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, starting from 0.|

## Return Value

Specified output offset. If the output index is invalid or the tensor does not carry non-contiguous description information, **-1** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto offset_0 = context->GetOutputOffset(0);
  ...
}
```
