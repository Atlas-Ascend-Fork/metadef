# SetStorageFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:32:43.749Z pushedAt=2026-10-15T03:48:05.070Z -->

## Function

Sets the data format of the runtime tensor.

## Function Prototype

```cpp
void SetStorageFormat(const ge::Format storage_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|storage_format|Input|Runtime data format. For the definition of the **ge::Format** type, see **Format**.|

## Return Value

None

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetOriginFormat(ge::FORMAT_NHWC);
t.SetStorageFormat(ge::FORMAT_NC1HWC0);
auto fmt = t.GetStorageFormat(); // ge::FORMAT_NC1HWC0
```
