# GetPlatformInfo

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T04:42:32.674Z pushedAt=2026-10-15T03:48:05.088Z -->

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

For details about the **PlatformAscendC** APIs, see [Ascend C API](https://gitcode.com/cann/asc-devkit/blob/master/docs/zh/api/README.md).

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
