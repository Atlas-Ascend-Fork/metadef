# GetListListFloat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:55:28.234Z pushedAt=2026-10-15T03:48:04.987Z -->

## Function

Obtains the attribute value of the **ContinuousVectorVector \*** type, that is, a two-dimensional array in which each element is of the **float** type.

## Function Prototype

```cpp
const ContinuousVectorVector *GetListListFloat(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the attribute in the IR prototype definition.|

## Return Value

Pointer to the attribute value.

## Constraints

None

## Example

```cpp
// Assume that in the IR prototype definition of an operator, the first attribute is of the two-dimensional float array type.
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const ContinuousVectorVector *attr0 = runtime_attrs->GetListListFloat(0);
```
