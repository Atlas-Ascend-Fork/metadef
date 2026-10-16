# GetKernelName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:58:04.217Z pushedAt=2026-10-15T03:48:04.886Z -->

## Function

Obtains the name of this kernel.

## Function Prototype

```cpp
const ge::char_t *GetKernelName() const
```

## Parameters

None

## Return Value

Name of this kernel.

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto kernel_name = extend_context->GetKernelName();
```
