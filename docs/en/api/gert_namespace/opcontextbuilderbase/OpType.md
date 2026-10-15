# OpType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:25:04.149Z pushedAt=2026-10-15T03:48:04.929Z -->

## Function

Sets the operator type, which is used to construct the **ComputeNodeInfo** information in the **ExtendedKernelContext** base class of each subclass context.

## Function Prototype

```cpp
T &OpType(const ge::AscendString &op_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_type|Input|Operator type.|

## Return Value

Returns a reference of type **T** to the subclass object, which is used to support chained calls on the subclass.

## Constraints

None
