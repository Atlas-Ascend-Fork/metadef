# CompiledInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:48:21.860Z pushedAt=2026-10-15T03:48:04.972Z -->

## Function

Sets the **CompiledInfo** pointer of the operator, which is used to store the result of **TilingParse**, that is, the **CompileInfo** information.

## Function Prototype

```cpp
OpTilingParseContextBuilder &CompiledInfo(const void *compile_info)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|compile_info|Input|Compilation information pointer.|

## Return Value

**OpTilingParseContextBuilder** object, which is used for chained calls.

## Constraints

For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
