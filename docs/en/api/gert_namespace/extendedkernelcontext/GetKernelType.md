# GetKernelType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:58:48.121Z pushedAt=2026-10-15T03:48:04.888Z -->

## Function

Obtains the type of this kernel.

## Function Prototype

```cpp
const ge::char_t *GetKernelType() const
```

## Parameters

None

## Return Value

Type of this kernel.

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto kernel_type = extend_context->GetKernelType();
```
