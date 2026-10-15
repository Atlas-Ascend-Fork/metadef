# GetNodeName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:58:54.628Z pushedAt=2026-10-15T03:48:04.888Z -->

## Function

Obtains the name of the operator.

## Function Prototype

```cpp
const ge::char_t *GetNodeName() const
```

## Parameters

None

## Return Value

Operator name.

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto node_name = extend_context->GetNodeName();
```
