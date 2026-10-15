# OutputShapeDependOnCompute

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:32:49.631Z pushedAt=2026-10-15T03:48:04.942Z -->

## Function

Registers the output list whose shape depends on computation. For some operators, such as NonZero (which counts the number of non-zero values in a tensor), the output shape cannot be known before the computation is complete and can only be obtained after the operator computation is complete. When defining the prototype of such operators, you need to use the **OutputShapeDependOnCompute** API to identify them, and write the actual output shape to the output parameter in the operator kernel function, so that the framework can manage the output memory based on this information.

## Function Prototype

```cpp
OpImplRegisterV2 &OutputShapeDependOnCompute(std::initializer_list<int32_t> outputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|outputs|Input|Specifies the output index list.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the output list whose shape depends on computation.

## Constraints

It can only be used to identify operator outputs.
