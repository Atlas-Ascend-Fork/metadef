# SetSimdNumBlocks

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T04:53:05.185Z pushedAt=2026-10-15T03:48:05.106Z -->

## Function

Sets the number of SIMD blocks, that is, the number of Vector or Cube cores participating in the computation.

## Function Prototype

```cpp
ge::graphStatus SetSimdNumBlocks(const uint32_t num_blocks)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|num_blocks|Input|**num_blocks** is a logical core concept, with a value range of [1,65535]. To fully utilize hardware resources, it is generally set to the number of physical cores or a multiple thereof.|

Additional description of this parameter is as follows:

- For coupled mode and decoupled mode, the runtime meaning and setting rules of **num_blocks** have some differences, as described below:
  - Coupled mode: Because the Vector and Cube units are integrated together, **num_blocks** is used to set the number of AI Core instances to launch for execution, without distinguishing between Vector and Cube. The number of AI Cores can be obtained through **GetCoreNumAiv** or **GetCoreNumAic**.
  - Decoupled mode: For operators that involve only Vector computation, **num_blocks** is used to set how many Vector (AIV) instances to launch for execution. For example, if an AI processor has 40 Vector cores, it is recommended to set it to **40**.
  - Decoupled mode: For operators that involve only Cube computation, **num_blocks** is used to set how many Cube (AIC) instances to launch for execution. For example, if an AI processor has 20 Cube cores, it is recommended to set it to **20**.
  - Decoupled mode: For operators that involve fused Vector/Cube computation, AIV and AIC are launched as a combination at startup, and **num_blocks** is used to set how many combinations to launch for execution. For example, if an AI processor has 40 Vector cores and 20 Cube cores, and one combination consists of 2 Vector cores and 1 Cube core, it is recommended to set it to **20**. In this case, 20 combinations are launched, that is, 40 Vector cores and 20 Cube cores. Note: In this scenario, the number of logical cores set by **num_blocks** cannot exceed the number of physical cores (2 Vector cores and 1 Cube core form 1 physical core).
  - Decoupled mode: The number of AIC/AIV cores is obtained through the **GetCoreNumAiv** or **GetCoreNumAic** API, respectively.
- When the device resource limit is configured, the number of cores set for **num_blocks** must not exceed the number of physical cores obtained through APIs such as **GetCoreNumAiv**. For example, if **aclrtSetStreamResLimit** is used to set the stream-level device resource limit to 8 cores, **num_blocks** must not exceed 8; otherwise, resources of other streams will be preempted, causing the resource limit to become invalid.
- If developers use the device resource limit feature, the **num_blocks** set for the operator must not exceed the number of cores returned by the APIs provided by **PlatformAscendC** for obtaining the number of cores (such as **GetCoreNum**/**GetCoreNumAic**/**GetCoreNumAiv**). For example, if **aclrtSetStreamResLimit** is used to set the stream-level Vector core count to 8, **GetCoreNumAiv** returns 8, and the **num_blocks** set for Vector operators must not exceed 8; otherwise, resources of other streams will be preempted, causing the resource limit to become invalid.

> [!NOTE] Note
>
> - For details about the APIs for obtaining the number of cores such as **GetCoreNumAiv** and **PlatformAscendC**, see [Ascend C API](https://gitcode.com/cann/asc-devkit/blob/master/docs/zh/api/README.md).
>
> - For details about the **aclrtSetStreamResLimit** API, see [Runtime API](https://gitcode.com/cann/runtime/blob/master/docs/zh/api_ref/README.md).

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetSimdNumBlocks(32);
  // ...
}
```
