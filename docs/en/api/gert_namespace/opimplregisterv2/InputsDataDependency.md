# InputsDataDependency

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:30:02.934Z pushedAt=2026-10-15T03:48:04.938Z -->

## Function

Sets which input tensor value the operator computation depends on.

Data dependency refers to the fact that an operator's computation depends not only on the shape of the input tensor but also on the specific value of the input tensor.

## Function Prototype

```cpp
OpImplRegisterV2 &InputsDataDependency(std::initializer_list<int32_t> inputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|inputs|Input|Specifies the list of input indexes on which the operator computation depends. For example, inputs={0, 3} indicates that the computation of this operator depends on the tensor values of the 0th and 3rd inputs.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which additionally sets which input tensor value the operator computation depends on.

## Constraints

None
