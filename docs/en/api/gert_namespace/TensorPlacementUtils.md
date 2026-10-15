# TensorPlacementUtils

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:22:48.298Z pushedAt=2026-10-15T03:48:04.786Z -->

## Function

Provides a set of functions to determine the location of **TensorPlacement**.

## Function Prototype

```cpp
class TensorPlacementUtils {
 public:
  // Check whether the tensor is in device memory.
  static bool IsOnDevice(TensorPlacement placement) {
    ...
  }
  // Check whether the tensor is on the host.
  static bool IsOnHost(TensorPlacement placement) {
    ...
  }
  // Check whether the tensor is on the host and the data immediately follows the structure.
  static bool IsOnHostFollowing(TensorPlacement placement) {
    ...
  }
  // Check whether the tensor is on the host and the data does not immediately follow the structure.
  static bool IsOnHostNotFollowing(TensorPlacement placement) {
    ...
  }
  // Check whether the tensor is in device memory.
  static bool IsOnDeviceHbm(TensorPlacement placement) {
    ...
  }
  // Check whether the tensor is in P2P memory on the device.
  static bool IsOnDeviceP2p(TensorPlacement placement) {
    ...
  }
};
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|placement|Input|**TensorPlacement** enumeration to be checked.|

## Return Value

**true** if yes; **false** otherwise.

## Constraints

None

## Example

```cpp
TensorData tensor_data;
tensor_data.SetPlacement(TensorPlacement::kOnHost);
auto on_host = TensorPlacementUtils::IsOnHost(tensor_data.GetPlacement()); // on_host is true
```
