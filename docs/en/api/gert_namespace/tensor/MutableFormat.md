# MutableFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:16:07.899Z pushedAt=2026-10-15T03:48:05.033Z -->

## Function

Obtains the format of the **Tensor**, including the runtime format and the original format.

## Function Prototype

```cpp
StorageFormat &MutableFormat()
```

## Parameters

None

## Return Value

Format reference.

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
auto fmt = tensor.MutableFormat();
```
