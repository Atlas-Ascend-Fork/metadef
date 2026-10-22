# GetShapeRange

<!-- md-trans-meta sourceCommit=1bfbd0f0dd6167ab870bed0b96c0f83575d5fca8 translatedAt=2026-10-16T01:38:14.765Z pushedAt=2026-10-16T02:00:17.875Z -->

## Function

Obtains the configured shape change range.

## Function Prototype

```cpp
graphStatus GetShapeRange(std::vector<std::pair<int64_t,int64_t>> &range) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**range**|Output|Configured shape change range.|

## Return Value

**graphStatus** type: On success, the value is **GRAPH\_SUCCESS** (that is, **0**); other values indicate a failure.

## Exception Handling

None

## Constraints

None
