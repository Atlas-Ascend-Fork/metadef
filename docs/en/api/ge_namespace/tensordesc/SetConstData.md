# SetConstData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:07:05.825Z pushedAt=2026-10-15T03:48:04.766Z -->

## Function

Sets the weight value into **TensorDesc** if **TensorDesc** is the description of a constant node.

## Function Prototype

```cpp
void SetConstData(std::unique_ptr<uint8_t[]> const_data_buffer, const size_t &const_data_len)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|const_data_buffer|Input|Weight address.|
|const_data_len|Input|Weight length.|

## Return Value

None

## Exception Handling

None

## Constraints

None
