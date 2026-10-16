# gert\_TilingContextBuilder\_SetDeterministicLevel

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:03:00.476Z pushedAt=2026-10-15T03:48:04.666Z -->

## Function

Sets the deterministic computation level when constructing a **TilingContext** using **OpTilingContextBuilder**. This corresponds to the weak-symbol C API and is equivalent to [OpTilingContextBuilder::DeterministicLevel](../gert_namespace/optilingcontextbuilder/DeterministicLevel.md).

## Function Prototype

```c
uint32_t __attribute__((weak)) gert_TilingContextBuilder_SetDeterministicLevel(void *builder, int32_t deterministic_level)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|builder|Input|Pointer to **OpTilingContextBuilder**.|
|deterministic_level|Input|Deterministic computation level (**0** for non-deterministic, **1** for deterministic, **2** for strong consistency, and **3** for batch consistency).|

## Return Value

Status code. **0** indicates success.

## Constraints

None

## Example

```cpp
OpTilingContextBuilder ctx_builder;
auto ret = gert_TilingContextBuilder_SetDeterministicLevel(reinterprete_cast<void *>(&ctx_builder), 2);
```
