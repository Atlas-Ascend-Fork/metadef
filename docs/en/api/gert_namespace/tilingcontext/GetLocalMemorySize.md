# GetLocalMemorySize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:38:54.123Z pushedAt=2026-10-15T03:48:05.081Z -->

## Function

Obtains the required Dynamic Unified Buffer size for SIMT operators.

**This API is deprecated and will be removed in a later version. Use [GetDynUBufSize](GetDynUBufSize.md) to obtain the required Dynamic Unified Buffer size.**

## Function Prototype

```cpp
uint32_t GetLocalMemorySize()
```

## Parameters

None

## Return Value

Returns the size of **Local Memory**. If **SetLocalMemorySize** has not been called previously, **0** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto local_memory_size = context->GetLocalMemorySize();
  // ...
}
```
