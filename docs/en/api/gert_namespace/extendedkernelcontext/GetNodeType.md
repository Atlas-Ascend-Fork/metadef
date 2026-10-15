# GetNodeType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:59:45.093Z pushedAt=2026-10-15T03:48:04.889Z -->

## Function

Obtains the type of the operator.

## Function Prototype

```cpp
const ge::char_t *GetNodeType() const
```

## Parameters

None

## Return Value

Operator type.

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto node_type = extend_context->GetNodeType();
```
