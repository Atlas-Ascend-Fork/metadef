# GetAttrNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:53:29.191Z pushedAt=2026-10-15T03:48:04.982Z -->

## Function

Obtains the number of attributes.

## Function Prototype

```cpp
size_t GetAttrNum() const
```

## Parameters

None

## Return Value

Number of attributes.

## Constraints

None

## Example

```cpp
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
size_t attr_num = runtime_attrs->GetAttrNum();
```
