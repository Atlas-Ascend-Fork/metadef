# TensorVersion

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:23:07.725Z pushedAt=2026-10-15T03:48:04.787Z -->

The header file is located in **include/exe\_graph/runtime/tensor.h** under the file storage path after CANN software installation.

```cpp
enum TensorVersion : uint8_t {
  kTensorV1 = 0, ///< Do not carry non-contiguous description information.
  kTensorV2 = 1, ///< Carry non-contiguous description information.
};
```
