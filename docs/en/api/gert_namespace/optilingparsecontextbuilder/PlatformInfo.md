# PlatformInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:50:33.372Z pushedAt=2026-10-15T03:48:04.977Z -->

## Function

Sets the **PlatFormInfo** pointer of the operator to construct the **PlatformInfo** field of **TilingParseContext**.

## Function Prototype

```cpp
OpTilingParseContextBuilder &PlatformInfo(const void *platform_info)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|platform_info|Input|Platform information pointer.|

## Return Value

**OpTilingParseContextBuilder** object, which is used for chained calls.

## Constraints

For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
