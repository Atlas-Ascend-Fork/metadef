# SetOriginShapeDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:58:43.311Z pushedAt=2026-10-15T03:48:04.753Z -->

## Function

Sets the *idx*-th dimension of the original shape.

## Function Prototype

```cpp
graphStatus SetOriginShapeDim(const size_t idx, const int64_t dim_value)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|idx|Input|Index of the dimension, starting from 0.|
|dim_value|Input|Value to be set.|

## Return Value

**graphStatus** type: Returns **GRAPH\_SUCCESS** on success; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

None
