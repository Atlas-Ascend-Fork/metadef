# GetDynUBufSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:36:57.669Z pushedAt=2026-10-15T03:48:05.079Z -->

## Function

Obtains the required **Dynamic Unified Buffer** size for SIMT operators.

## Function Prototype

```cpp
uint32_t GetDynUBufSize()
```

## Parameters

None

## Return Value

Returns the **Dynamic Unified Buffer** size. If **SetDynUBufSize** was not called previously to set it, **0** is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
    // ...
    auto dyn_ubuf_size = context->GetDynUBufSize();
}
```
