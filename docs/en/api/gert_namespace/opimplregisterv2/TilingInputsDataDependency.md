# TilingInputsDataDependency

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:33:54.405Z pushedAt=2026-10-15T03:48:04.944Z -->

## Function

Marks which input tensor value of the operator the tiling computation depends on, and marks the positions where the Tiling computation can be executed.

## Function Prototype

```cpp
OpImplRegisterV2 &TilingInputsDataDependency(std::initializer_list<int32_t> inputs)
OpImplRegisterV2 &TilingInputsDataDependency(std::initializer_list<int32_t> inputs, std::initializer_list<TilingPlacement> placements)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|inputs|Input|Specifies the list of input indexes that the operator tiling computation depends on. For example, inputs={0, 3} indicates that the tiling computation of this operator depends on the tensor values of the 0th and 3rd inputs.|
|placements|Input|Specifies the positions where the operator tiling computation can be executed. **0** indicates that execution on the host is supported, and **1** indicates that execution on the AI CPU is supported. If this parameter is not included, only execution on the host is supported.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which additionally registers the value of the *index*-th tensor of the input that the operator tiling value depends on, as well as the executable position.

## Constraints

None
