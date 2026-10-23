# IsScalar

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:58:29.595Z pushedAt=2026-10-15T03:48:04.994Z -->

## Function

Checks whether this shape is a scalar. A scalar means that **GetDimNum\(\)** is **0**.

## Function Prototype

```cpp
bool IsScalar() const
```

## Parameters

None

## Return Value

**true**/**false**.

## Constraints

None

## Example

```cpp
Shape shape0({3, 256, 256});
Shape shape2;
shape0.IsScalar(); // false
shape2.IsScalar(); // true
```
