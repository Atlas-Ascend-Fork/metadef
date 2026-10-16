# TilingParse

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:34:39.096Z pushedAt=2026-10-15T03:48:04.945Z -->

## Function

Registers the **TilingParse** function of an operator, which is used to parse the operator information JSON file generated during the operator compilation phase. During registration, the operator must specify the data type **T**, which is used to store the parsed operator information.

You need to write a function of the **KernelFunc** type or the **TilingParseFunc** type for the operator, and register it using the corresponding API below.

The **KernelFunc** type is defined as follows:

```cpp
using KernelFunc = UINT32 (*)(KernelContext *context);
```

The **TilingParseFunc** type is defined as follows:

```cpp
using TilingParseFunc = UINT32 (*)(TilingParseContext *context);
```

## Function Prototype

```cpp
template<typename T>
OpImplRegisterV2 &TilingParse(KernelFunc const tiling_parse_func)
template<typename T>
OpImplRegisterV2 &TilingParse(TilingParseFunc const tiling_parse_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|tiling_parse_func|Input|**TilingParse** function to be registered. Two types are supported: **KernelFunc** and **TilingParseFunc**.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **TilingParse** function.

## Constraints

None
