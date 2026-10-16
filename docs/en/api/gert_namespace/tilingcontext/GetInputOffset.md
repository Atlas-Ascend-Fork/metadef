# GetInputOffset

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:37:13.469Z pushedAt=2026-10-15T03:48:05.079Z -->

## Function

Obtains the corresponding input offset based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

> [!NOTE] Note
> This is a reserved API kept for future functionality, and is not supported in the current version.

## Function Prototype

```cpp
int64_t GetInputOffset(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Specified input offset. If the input index is invalid or the tensor does not carry non-contiguous description information, **-1** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForMul(TilingContext *context) {
  auto offset_0 = context->GetInputOffset(0);
  ...
}
```
