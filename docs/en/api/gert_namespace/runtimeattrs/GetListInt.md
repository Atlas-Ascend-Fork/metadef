# GetListInt

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:55:03.094Z pushedAt=2026-10-15T03:48:04.986Z -->

## Function

Obtains the attribute value of the **list int** type.

## Function Prototype

```cpp
const TypedContinuousVector<int64_t> *GetListInt(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the attribute in the IR prototype definition and in the **OP_IMPL** registration.|

## Return Value

Pointer to the attribute value.

For the definition of the **TypedContinuousVector** type, see [TypedContinuousVector](../typedcontinuousvector/TypedContinuousVector.md).

## Constraints

None

## Example

```cpp
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const TypedContinuousVector<int64_t> *attr0 = runtime_attrs->GetListInt(0);
```
