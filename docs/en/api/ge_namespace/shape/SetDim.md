# SetDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:50:23.361Z pushedAt=2026-10-15T03:48:04.739Z -->

## Function

Sets the value of the *idx*-th dimension in a shape to **value**.

## Function Prototype

```cpp
graphStatus SetDim(size_t idx, int64_t value)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|idx|Input|Index of the dimension in a shape, starting from 0.|
|value|Input|Value to be set.|

## Return Value

**graphStatus** type: Returns **GRAPH\_SUCCESS** on success; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

Before using the **SetDim** API, you can only use **Shape\(const std::vector<int64\_t\>& dims\)** to construct a shape object. If you use **Shape\(\)** to construct a shape object, the **SetDim** API returns a failure.
