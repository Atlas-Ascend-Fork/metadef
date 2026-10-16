# operator=

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:21:26.766Z pushedAt=2026-10-15T03:48:05.046Z -->

## Function

Disables the copy assignment operator.

Uses the move assignment operator.

## Function Prototype

```cpp
TensorData& operator= (const TensorData &other)=delete
TensorData& operator= (TensorData &&other) noexcept
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|other|Input|Another **TensorData** object.|

## Return Value

Returns a new **TensorData** object that holds the resources of the **other** object.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
TensorData new_td = td;
```
