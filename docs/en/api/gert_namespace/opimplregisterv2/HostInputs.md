# HostInputs

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:27:32.178Z pushedAt=2026-10-15T03:48:04.933Z -->

## Function

When an operator has scalar inputs, the host-side addresses must be passed in. This interface marks which input of the operator has a host-side address.

## Function Prototype

```cpp
OpImplRegisterV2 &HostInputs(std::initializer_list<int32_t> inputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|inputs|Input|Specifies the list of input indexes. For example, inputs={0, 3} indicates that the addresses of the 0th and 3rd inputs of the operator are host-side addresses.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the function for marking which input of the operator has a host-side address.

## Constraints

None
