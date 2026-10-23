# SetAicpuNumBlocks

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:14:32.146Z pushedAt=2026-10-15T07:29:17.895Z -->

## Function

Sets the number of AI CPU cores that can be scheduled.

When using the **BatchWrite** API of the HCCL advanced API, you can achieve better performance by properly setting the number of AI CPU cores.

For details about the **BatchWrite** API, see "SIMD API > Advanced APIs > HCCL Communication Class" in *[Ascend C API](https://gitcode.com/cann/asc-devkit/blob/9.2.0/docs/zh/api/README.md)*.

## Function Prototype

```cpp
ge::graphStatus SetAicpuNumBlocks(uint32_t num_blocks)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|SetAicpuNumBlocks|Input|Number of AI CPU cores that can be scheduled.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetAicpuNumBlocks(5U);
  // ...
}
```
