# GetPlacement

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:20:17.855Z pushedAt=2026-10-15T03:48:05.043Z -->

## Function

Obtains the placement of the tensor, which is the device location where the tensor data resides.

## Function Prototype

```cpp
TensorPlacement GetPlacement() const
```

## Parameters

None

## Return Value

Placement of the tensor. For the definition of the **TensorPlacement** type, see [TensorPlacement](../TensorPlacement.md).

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
auto td_place = td.GetPlacement(); // kOnHost
```
