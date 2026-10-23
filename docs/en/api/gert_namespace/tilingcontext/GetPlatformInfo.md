# GetPlatformInfo

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:14:00.539Z pushedAt=2026-10-15T07:29:17.895Z -->

## Function

Obtains the **PlatformInfos** pointer. The **PlatformInfos** class is used to manage and query hardware platform information, including core quantity, memory bandwidth, and more.

## Function Prototype

```cpp
fe::PlatFormInfos *GetPlatformInfo() const
```

## Parameters

None

## Return Value

The **PlatformInfos** pointer holds the internal hardware platform information, which serves as the input to **PlatformAscendC**. Developers obtain the hardware platform information through the methods provided by **PlatformAscendC**.

For details about the **PlatformAscendC** APIs, see *[Ascend C API](https://gitcode.com/cann/asc-devkit/blob/9.2.0/docs/zh/api/README.md)*.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingXXX(gert::TilingContext* context) {
    auto ascendcPlatform = platform_ascendc::PlatformAscendC(context->GetPlatformInfo());
    auto coreNum = ascendcPlatform.GetCoreNum();
    // ... Design the tiling strategy based on the core quantity.
    context->SetBlockDim(coreNum);
    return ret;
}
```
