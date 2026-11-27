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

Returns a pointer to a **const RuntimeAttrs** object containing all attribute values defined by the IR prototype, with the attribute values stored in the order defined by the IR prototype. If the underlying **KernelContext** does not contain compute-node information, returns **nullptr**.

## Constraints

Check the returned pointer for **nullptr** before dereferencing it. The pointer is owned by the underlying context and remains valid only while that context remains valid.

## Example

```cpp
#include <exe_graph/runtime/extended_kernel_context.h>

void ReadAttrs(gert::KernelContext *context) {
  auto extend_context = reinterpret_cast<gert::ExtendedKernelContext *>(context);
  const auto *rt_attrs = extend_context->GetAttrs();
  if (rt_attrs == nullptr) {
    return;
  }
  // Use rt_attrs while context remains valid.
}
```
