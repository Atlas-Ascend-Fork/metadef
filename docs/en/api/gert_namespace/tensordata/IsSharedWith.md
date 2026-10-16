# IsSharedWith

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:21:18.940Z pushedAt=2026-10-15T03:48:05.045Z -->

## Function

Checks whether the current **TensorData** object shares the same memory block and uses the same memory management function as another object.

## Function Prototype

```cpp
bool IsSharedWith(const TensorData &other) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|other|Input|Another **TensorData** object.|

## Return Value

**true** indicates that the two objects share the same memory block and use the same memory management function; **false** indicates otherwise.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td1(addr, HostAddrManager, 100U, kOnHost);
TensorData td2(addr, HostAddrManager, 100U, kOnHost);
bool is_shared_td = td1.IsSharedWith(td2); // true
```
