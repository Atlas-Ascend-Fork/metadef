# ResetData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:56:25.485Z pushedAt=2026-10-15T03:48:04.749Z -->

## Function

Releases the data memory in a tensor.

## Function Prototype

```cpp
std::unique_ptr<uint8_t[], Tensor::DeleteFunc> ResetData()
```

## Parameters

None

## Return Value

Returns the released memory address and deleter.

## Exception Handling

None

## Constraints

None
