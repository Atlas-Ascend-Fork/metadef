# ShareFrom

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:22:38.931Z pushedAt=2026-10-15T03:48:05.049Z -->

## Function

Makes the current **TensorData** object share the memory and memory management functions of another object.

## Function Prototype

```cpp
ge::graphStatus ShareFrom(const TensorData &other)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|other|Input|Another **TensorData** object.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td1(addr, HostAddrManager, 100U, kOnHost);
TensorData td2(addr, nullptr);
td2.ShareFrom(td1);
```
