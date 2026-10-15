# IOInstanceNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:23:25.830Z pushedAt=2026-10-15T03:48:04.927Z -->

## Function

When the number of instances of an input IR prototype is not 1 (typically in optional-input or dynamic-input scenarios), you need to set the number of instances of each input IR prototype of the operator to construct the **ComputeNodeInfo** information in the base class **ExtendedKernelContext** of each subclass **Context**.

## Function Prototype

```cpp
T &IOInstanceNum(const std::vector<uint32_t> &input_instance_num, const std::vector<uint32_t> &output_instance_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|input_instance_num|Input|A vector array input. The size of the vector represents the number of inputs of the operator prototype, and the number at each position in the vector array represents the number of instances of each IR prototype input.|
|output_instance_num|Input|A vector array input. The size of the vector represents the number of outputs of the operator prototype, and the number at each position in the vector array represents the number of instances of each IR prototype output.|

## Return Value

Returns a reference of the subclass object type **T** to support chained calls on the subclass.

## Constraints

This API is mutually exclusive with the [IONum](IONum.md) API. You only need to call one of the two APIs, and the API called first takes effect.
