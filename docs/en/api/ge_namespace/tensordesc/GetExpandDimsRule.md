# GetExpandDimsRule

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:02:45.174Z pushedAt=2026-10-15T03:48:04.760Z -->

## Function

Obtains the dimension expansion rule of a tensor.

## Function Prototype

```cpp
graphStatus GetExpandDimsRule(AscendString &expand_dims_rule) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|expand_dims_rule|Input by reference|Obtained dimension expansion rule, which is used as an output parameter.|

## Return Value

**graphStatus** type: Returns **GRAPH\_SUCCESS** on success; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

None
