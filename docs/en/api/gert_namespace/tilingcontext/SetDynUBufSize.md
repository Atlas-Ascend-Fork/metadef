# SetDynUBufSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:51:00.795Z pushedAt=2026-10-15T03:48:05.102Z -->

## Function

Sets the size of the Dynamic Unified Buffer to be used for a SIMT operator. If not set, the default value is **0**, meaning that the operator does not need to use the Dynamic Unified Buffer.

## Function Prototype

```cpp
ge::graphStatus SetDynUBufSize(const uint32_t dyn_ubuf_size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|local_memory_size|Input|Size of the Dynamic Unified Buffer.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
    // ...
    auto ret = context->SetDynUBufSize(1024 * 128);
}
```
