# Release

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:21:43.363Z pushedAt=2026-10-15T03:48:05.046Z -->

## Function

Releases ownership of **TensorAddress**. After this API is called, this object no longer manages **TensorAddress**, and **TensorAddress** is not released. Therefore, the caller is responsible for releasing **TensorAddress** through **manager**.

## Function Prototype

```cpp
TensorAddress Release(TensorAddrManager &manager)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|manager|Output|Manager function for the tensor, which is used to manage the returned **TensorAddress**. If this object has no ownership, **manager** is set to **nullptr**.|

## Return Value

**TensorAddress** pointer held by this object. If this object does not hold any pointer, **nullptr** is returned.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
TensorAddrManager NewHostAddrManager = nullptr;
TensorAddress ta = td.Release(NewHostAddrManager);
```
