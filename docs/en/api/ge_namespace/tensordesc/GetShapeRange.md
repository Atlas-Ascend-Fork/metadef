# GetShapeRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:06:17.669Z pushedAt=2026-10-15T03:48:04.765Z -->

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

**graphStatus** type: On success, the value is GRAPH\_SUCCESS\(that is, 0\); otherwise, the value indicates execution failure.

## Exception Handling

None

## Constraints

None
