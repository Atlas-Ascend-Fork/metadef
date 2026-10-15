# GetAttrs

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:54:33.904Z pushedAt=2026-10-15T03:48:04.881Z -->

## Function

Obtains the attribute values of the operator. Only the attribute values defined in the operator's IR prototype definition are returned; other attribute values are discarded.

## Function Prototype

```cpp
const RuntimeAttrs *GetAttrs() const
```

## Parameters

None

## Return Value

A **const**-type object containing all attribute values defined by the IR prototype, with the attribute values stored in the order defined by the IR prototype.

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto rt_attrs = extend_context->GetAttrs();
```
