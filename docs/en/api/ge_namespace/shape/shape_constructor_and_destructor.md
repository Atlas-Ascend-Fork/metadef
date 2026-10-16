# Shape Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:50:24.205Z pushedAt=2026-10-15T03:48:04.740Z -->

## Function

Shape constructor and destructor.

## Function Prototype

```cpp
Shape()
~Shape() = default
explicit Shape(const std::vector<int64_t> &dims)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|dims|Input|Value of a shape. The shape represents the dimension size of tensor data, and **std::vector<int64_t>** represents the specific size of each dimension.|

## Return Value

The shape constructor returns an object of the **Shape** type.

## Exception Handling

None

## Constraints

None
