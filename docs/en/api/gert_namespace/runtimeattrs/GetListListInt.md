# GetListListInt

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:55:33.059Z pushedAt=2026-10-15T03:48:04.988Z -->

## Function

Obtains the attribute value of the **ContinuousVectorVector \*** type, that is, a two-dimensional array in which each element is of the **int** type.

## Function Prototype

```cpp
const ContinuousVectorVector *GetListListInt(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the attribute in the IR prototype definition.|

## Return Value

Pointer to the attribute value.

For the definition of the **ContinuousVectorVector** type, see [ContinuousVectorVector](../continuousvectorvector/ContinuousVectorVector.md).

## Constraints

None

## Example

```cpp
// Assume that in the IR prototype definition of an operator, the value of the first attribute is a two-dimensional int array.
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const ContinuousVectorVector *attr0 = runtime_attrs->GetListListInt(0);
```
