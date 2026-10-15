# SetOriginFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:58:11.411Z pushedAt=2026-10-15T03:48:04.752Z -->

## Function

Sets the original format of the tensor.

This format refers to the format of the original network model.

## Function Prototype

```cpp
graphStatus SetOriginFormat(const ge::Format &format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Original format value to be set. For details about the **Format** type, see **Format**.|

## Return Value

**graphStatus** type: Returns **GRAPH_SUCCESS** on success; otherwise, returns **GRAPH_FAILED**.

## Exception Handling

None

## Constraints

None
