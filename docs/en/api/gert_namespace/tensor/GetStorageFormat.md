# GetStorageFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:14:35.564Z pushedAt=2026-10-15T03:48:05.030Z -->

## Function

Obtains the format of the runtime tensor.

## Function Prototype

```cpp
ge::Format GetStorageFormat() const
```

## Parameters

None

## Return Value

Returns the runtime format.

For the definition of the **ge::Format** type, see [Format](../../ge_namespace/Format.md).

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetOriginFormat(ge::FORMAT_NHWC);
t.SetStorageFormat(ge::FORMAT_NC1HWC0);
auto fmt = t.GetStorageFormat(); // ge::FORMAT_NC1HWC0
```
