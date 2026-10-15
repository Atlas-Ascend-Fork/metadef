# SetOriginFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:32:08.239Z pushedAt=2026-10-15T03:48:05.068Z -->

## Function

Sets the original data format of a tensor.

## Function Prototype

```cpp
void SetOriginFormat(const ge::Format origin_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|origin_format|Input|Original data format. For the definition of the **ge::Format** type, see **Format**.|

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
auto fmt = t.GetOriginFormat(); // ge::FORMAT_NHWC
```
