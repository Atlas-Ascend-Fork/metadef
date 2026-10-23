# SetDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:57:15.558Z pushedAt=2026-10-15T03:48:04.751Z -->

## Function

Sets the data type of a tensor.

## Function Prototype

```cpp
graphStatus SetDataType(const ge::DataType &dtype)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|dtype|Input|**DataType** value to set. For details about the **DataType** type, see DataType.|

## Return Value

**graphStatus** type: Returns **GRAPH\_SUCCESS** on success; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

None
