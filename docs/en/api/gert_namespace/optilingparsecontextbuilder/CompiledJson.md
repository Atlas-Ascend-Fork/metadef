# CompiledJson

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:48:44.021Z pushedAt=2026-10-15T03:48:04.973Z -->

## Function

Sets the **CompiledJson** pointer of the operator, which is a pointer to a JSON-format file.

## Function Prototype

```cpp
OpTilingParseContextBuilder &CompiledJson(const ge::char_t *compiled_json)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|compiled_json|Input|Pointer to the compilation information JSON file.|

## Return Value

**OpTilingParseContextBuilder** object, which is used for chained calls.

## Constraints

For parameters passed by pointers (**ge::char\_t \***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
