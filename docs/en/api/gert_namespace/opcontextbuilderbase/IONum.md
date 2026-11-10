# IONum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:23:47.416Z pushedAt=2026-10-15T03:48:04.926Z -->

## Function

Sets the numbers of input and output IR prototypes of an operator to construct ComputeNodeInfo for each subclass Context. By default, each input and output IR prototype has one instance.

## Function Prototype

```cpp
T &IONum(size_t input_ir_num, size_t output_ir_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|input_ir_num|Input|Number of input IR prototypes.|
|output_ir_num|Input|Number of output IR prototypes.|

## Return Value

Returns a reference to the subclass object of type **T**, which supports chained calls on the subclass.

## Constraints

- If this API or [IOInstanceNum](IOInstanceNum.md) is called more than once, the last call determines the input and output count configuration.
- Determine the input and output counts using `IONum()` or `IOInstanceNum()` before setting Tensors and their descriptions. After Tensors have been supplied, the input and output count configuration must not be changed; create a new Builder if changes are needed.
