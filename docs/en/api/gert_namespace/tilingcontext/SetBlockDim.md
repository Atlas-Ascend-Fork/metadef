# SetBlockDim

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T04:50:54.271Z pushedAt=2026-10-15T03:48:05.103Z -->

## Function

Sets **blockDim**, that is, the number of Vector or Cube cores participating in the computation.

This parameter will be deprecated in later versions. It is recommended that you use [SetSimdNumBlocks](SetSimdNumBlocks.md) instead.

## Function Prototype

```cpp
ge::graphStatus SetBlockDim(const uint32_t block_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|block_dim|Input|**blockDim** is a logical core concept, with a value range of [1, 65535]. To make full use of hardware resources, it is generally set to the number of physical cores or a multiple thereof.|

The supplementary description of this parameter is as follows:

- For coupled mode and decoupled mode, the runtime meaning and setting rules of **blockDim** differ. The details are as follows:
  - Coupled mode: Because the Vector and Cube units are integrated together, **blockDim** is used to set the number of AI Core instances to be launched for execution, without distinguishing between Vector and Cube. The number of AI Cores can be obtained through **GetCoreNumAiv** or **GetCoreNumAic**.
  - Decoupled mode: For operators that involve only Vector computation, **blockDim** is used to set the number of Vector (AIV) instances to be launched for execution. For example, if an AI processor has 40 Vector cores, it is recommended to set it to **40**.
  - Decoupled mode: For operators that involve only Cube computation, **blockDim** is used to set the number of Cube (AIC) instances to be launched for execution. For example, if an AI processor has 20 Cube cores, it is recommended to set it to **20**.
  - Decoupled mode: For operators that involve fused Vector/Cube computation, the launch is performed in combinations of AIV and AIC. **blockDim** is used to set the number of combinations to be launched for execution. For example, if an AI processor has 40 Vector cores and 20 Cube cores, and one combination consists of 2 Vector cores and 1 Cube core, it is recommended to set it to **20**. In this case, 20 combinations are launched, that is, 40 Vector cores and 20 Cube cores. **Note: In this scenario, the number of logical cores set for blockDim cannot exceed the number of physical cores (2 Vector cores and 1 Cube core form 1 physical core).**
  - Decoupled mode: The numbers of AIC and AIV cores are obtained through the **GetCoreNumAic** and **GetCoreNumAiv** APIs, respectively.
- When a device resource limit is set, the number of **blockDim** cores must not exceed the number of physical cores obtained through APIs such as **GetCoreNumAiv**. For example, if **aclrtSetStreamResLimit** is used to set the stream-level device resource limit to 8 cores, **blockDim** must not exceed 8; otherwise, resources of other streams are preempted, causing the resource limit to become invalid.
- If developers use the device resource limit feature, the **blockDim** set for the operator must not exceed the number of cores returned by the APIs provided by **PlatformAscendC** for obtaining the core count (such as **GetCoreNum**/**GetCoreNumAic**/**GetCoreNumAiv**). For example, if **aclrtSetStreamResLimit** is used to set the stream-level Vector core count to 8, the **GetCoreNumAiv** API returns 8, and the **blockDim** set for a Vector operator must not exceed 8; otherwise, resources of other streams are preempted, causing the resource limit to become invalid.

> [!NOTE] Note
>
> - For details about the core count APIs such as **GetCoreNumAiv** and **PlatformAscendC**, see *[Ascend C API](https://gitcode.com/cann/asc-devkit/blob/master/docs/zh/api/README.md)*.
>
> - For details about the **aclrtSetStreamResLimit** API, see *[Runtime API](https://gitcode.com/cann/runtime/blob/master/docs/zh/api_ref/README.md)*.

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetBlockDim(32);
  // ...
}
```
