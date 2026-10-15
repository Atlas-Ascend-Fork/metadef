# GetFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:12:21.195Z pushedAt=2026-10-15T03:48:05.024Z -->

## Function

Obtains the format of a tensor, including the runtime format and the original format. The returned format objects are read-only.

## Function Prototype

```cpp
const StorageFormat &GetFormat() const
```

## Parameters

None

## Return Value

Read-only reference to the format.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
              kFollowing,                                  // placement
              ge::DT_FLOAT16,                              //dt
              nullptr};
auto fmt = tensor.GetFormat();
```
