# SetPlacement

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:22:11.456Z pushedAt=2026-10-15T03:48:05.048Z -->

## Function

Sets the placement of a tensor.

## Function Prototype

```cpp
void SetPlacement(const TensorPlacement placement)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|placement|Input|Placement of the tensor. For the definition of the **TensorPlacement** type, see **TensorPlacement**.|

## Return Value

None

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
auto td_place = td.SetPlacement(kOnHost);
```
