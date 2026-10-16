# GetConstData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:01:48.471Z pushedAt=2026-10-15T03:48:04.758Z -->

## Function

Obtains the weight value in **TensorDesc** if **TensorDesc** is the description of a constant node.

## Function Prototype

```cpp
bool GetConstData(uint8_t **const_data_buffer, size_t &const_data_len) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|const_data_buffer|Output|Weight address.|
|const_data_len|Output|Weight length.|

## Return Value

Returns **true** on success.

Returns **false** on failure.

## Exception Handling

None

## Constraints

None
