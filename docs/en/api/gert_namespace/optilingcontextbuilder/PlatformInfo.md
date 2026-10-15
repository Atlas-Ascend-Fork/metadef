# PlatformInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:45:57.203Z pushedAt=2026-10-15T03:48:04.967Z -->

## Function

Sets the **PlatformInfo** platform information.

## Function Prototype

```cpp
OpTilingContextBuilder &PlatformInfo(const void *platform_info)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|platform_info|Input|Pointer to platform information.|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, this API must be called; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
