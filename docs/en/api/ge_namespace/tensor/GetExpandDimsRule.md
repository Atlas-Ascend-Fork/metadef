# GetExpandDimsRule

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:52:20.045Z pushedAt=2026-10-15T03:48:04.743Z -->

## Function

Obtains the **expand_dims_rule** of a tensor.

## Function Prototype

```cpp
graphStatus GetExpandDimsRule(AscendString &expand_dims_rule) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|expand_dims_rule|Input|**expand_dims_rule** to be returned by the function, which represents dimension expansion in string form.|

## Return Value

**graphStatus** type: Returns **GRAPH\_SUCCESS** on success; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

None
