# GetDimNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:57:56.597Z pushedAt=2026-10-15T03:48:04.993Z -->

## Function

Obtains the number of dimensions of a shape.

## Function Prototype

```cpp
size_t GetDimNum() const
```

## Parameters

None

## Return Value

Number of dimensions of a shape.

## Constraints

None

## Example

```cpp
Shape shape0({3, 256, 256});
auto dim_num = shape0.GetDimNum(); // 3
```
