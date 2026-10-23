# InputReorderVector

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:44:29.736Z pushedAt=2026-10-15T03:48:04.731Z -->

## Function

Supports adjusting the input parameter order of an operator in an operator plugin. This is an internal API and external developers do not need to concern themselves with it.

## Function Prototype

```cpp
OpRegistrationData &InputReorderVector(const std::vector<int32_t> &input_order)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|input_order|Input|Adjustment list of the operator inputs. The subscript indicates the original input index, and the value corresponding to the subscript indicates the new input index after adjustment. For example, the AI processor operator corresponding to operator A of a third-party framework is AD. The original input 0 is **in0**, the original input 1 is **in1**, and the original input 2 is **in2**. If the plugin calls the API with input_order = {1, 0, 2}, then after parsing, input 0 of operator AD is **in1**, input 1 is **in0**, and input 2 is **in2**.|

## Return Value

Reference to the **OpRegistrationData** class.

## Exception Handling

None

## Constraints

None
