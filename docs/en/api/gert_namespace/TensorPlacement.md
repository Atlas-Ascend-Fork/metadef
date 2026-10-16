# TensorPlacement

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:22:06.422Z pushedAt=2026-10-15T03:48:04.786Z -->

```cpp
enum TensorPlacement {
    kOnDeviceHbm,  ///< Tensor is located on the device.
    kOnHost,       ///< Tensor is located on the host.
    kFollowing,    ///< Tensor is located on the host, and the data immediately follows the structure.
    kOnDeviceP2p,  ///< Tensor is located on the device. P2P memory refers to the address space where device memory is exposed to the PCIE BAR space, allowing the NPU to access it across PCIE.
    kTensorPlacementEnd
};
```
