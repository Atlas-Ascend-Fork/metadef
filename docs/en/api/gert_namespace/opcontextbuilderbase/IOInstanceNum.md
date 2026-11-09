# IOInstanceNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:23:25.830Z pushedAt=2026-10-15T03:48:04.927Z -->

## Function

When the number of instances of an input IR prototype is not 1 (typically in optional-input or dynamic-input scenarios), set the instance count for each input IR prototype of the operator to construct ComputeNodeInfo for each subclass Context.

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

- If this API or [IONum](IONum.md) is called more than once, the last call determines the input and output count configuration.
- Determine the input and output counts using `IONum()` or `IOInstanceNum()` before setting Tensors and their descriptions. After Tensors have been supplied, the input and output count configuration must not be changed; create a new Builder if changes are needed.
