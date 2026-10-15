# SetShapeRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:13:11.289Z pushedAt=2026-10-15T03:48:04.773Z -->

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

**graphStatus** type: On success, the value is GRAPH\_SUCCESS\(that is, 0\); other values indicate a failure.

## Exception Handling

None

## Constraints

None
