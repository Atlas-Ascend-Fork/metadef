# GetFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:24:55.867Z pushedAt=2026-10-15T03:48:05.055Z -->

## Function

Obtains the data format of a tensor, including the runtime data format and the original data format. The returned **Format** objects are read-only.

## Function Prototype

```cpp
const StorageFormat &GetFormat() const
```

## Parameters

None

## Return Value

Read-only format reference.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                kFollowing,                                  // placement
                ge::DT_FLOAT16,                              //dt
                nullptr};
auto fmt = tensor.GetFormat();
```
