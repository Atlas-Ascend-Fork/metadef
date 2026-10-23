# GetFormatName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:14:29.606Z pushedAt=2026-10-15T03:48:04.678Z -->

## Function

Obtains the string description of **Format** based on the input **Format** type.

## Function Prototype

```cpp
const char_t *GetFormatName(Format format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**format**|Input|**Format** enumeration value.|

## Return Value

Returns the string description corresponding to the **Format**. If the **Format** is invalid or unrecognized, returns **nullptr**.

## Exception Handling

None

## Constraints

The returned string cannot be modified.
