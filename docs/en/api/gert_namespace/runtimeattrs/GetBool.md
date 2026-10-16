# GetBool

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:54:04.586Z pushedAt=2026-10-15T03:48:04.983Z -->

## Function

Obtains the attribute value of the **bool** type.

## Function Prototype

```cpp
const bool *GetBool(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the attribute in the IR prototype definition and in the **OP_IMPL** registration.|

## Return Value

Pointer to the attribute value.

## Constraints

None

## Example

```cpp
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const bool *attr0 = runtime_attrs->GetBool(0);
```
