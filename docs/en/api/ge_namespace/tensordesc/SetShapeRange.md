# SetShapeRange

<!-- md-trans-meta sourceCommit=1bfbd0f0dd6167ab870bed0b96c0f83575d5fca8 translatedAt=2026-10-16T01:38:15.585Z pushedAt=2026-10-16T02:00:17.876Z -->

## Function

Sets the variation range of the shape.

## Function Prototype

```cpp
graphStatus SetShapeRange(const std::vector<std::pair<int64_t,int64_t>> &range)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|range|Input|Variation range represented by the shape. Each element in the vector is a pair, where the first value of the pair is the minimum dim value on that dimension, and the second value is the maximum dim value on that dimension. For example, if the shape of the tensor is {1,1,-1,2} and the maximum value of the third axis is 100, **range** can be set to {{1,1},{1,1},{1,100},{2,2}}.|

## Return Value

**graphStatus** type: On success, the value is **GRAPH\_SUCCESS** (that is, **0**); other values indicate a failure.

## Exception Handling

None

## Constraints

None
