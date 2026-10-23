# OpName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:24:20.719Z pushedAt=2026-10-15T03:48:04.928Z -->

## Function

Sets the operator name, which is used to construct the **ComputeNodeInfo** information in the base class **ExtendedKernelContext** of each subclass **Context**.

## Function Prototype

```cpp
T &OpName(const ge::AscendString &op_name)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_name|Input|Operator name.|

## Return Value

Returns a reference of the subclass object type **T**, which supports chained calls on the subclass.

## Constraints

None
