# GetExtendInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:56:23.038Z pushedAt=2026-10-15T03:48:04.884Z -->

## Function

Obtains the extended information of this kernel.

## Function Prototype

```cpp
const KernelExtendInfo *GetExtendInfo() const
```

## Parameters

None

## Return Value

Extended information of this kernel.

For the definition of the **KernelExtendInfo** type, see [internal API](../internal_interface.md) **KernelExtendInfo** class.

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto extend_info = extend_context->GetExtendInfo();
```
