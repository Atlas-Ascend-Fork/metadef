# SetSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:22:31.473Z pushedAt=2026-10-15T03:48:05.048Z -->

## Function

Sets the memory size of the tensor data.

## Function Prototype

```cpp
void SetSize(const size_t size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|size|Input|Memory size of the tensor in bytes.|

## Return Value

None

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
td.SetSize(10U);
```
