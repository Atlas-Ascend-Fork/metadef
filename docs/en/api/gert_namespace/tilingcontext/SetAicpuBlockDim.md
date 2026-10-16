# SetAicpuBlockDim

<!-- md-trans-meta sourceCommit=be935a2e3ccf85ec208a4650797dabe60fc68a79 translatedAt=2026-10-09T04:50:00.024Z pushedAt=2026-10-15T03:48:05.101Z -->

## Function

Sets the number of AI CPU cores that can be scheduled.

When using the **BatchWrite** API of the HCCL advanced API, you can achieve better performance by properly setting the number of AI CPU cores.

For details about the **BatchWrite** API, see "SIMD API > Advanced APIs > HCCL Communication Class" in *[Ascend C API](https://gitcode.com/cann/asc-devkit/blob/master/docs/zh/api/README.md)*.

This parameter will be deprecated in later versions. It is recommended that you use [SetAicpuNumBlocks](SetAicpuNumBlocks.md).

## Function Prototype

```cpp
ge::graphStatus SetAicpuBlockDim(uint32_t block_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|block_dim|Input|Number of AI CPU cores that can be scheduled.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetAicpuBlockDim(5U);
  // ...
}
```
