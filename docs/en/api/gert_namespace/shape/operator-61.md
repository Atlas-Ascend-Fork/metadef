# operator!=

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:59:02.632Z pushedAt=2026-10-15T03:48:04.994Z -->

## Function

Checks whether this shape object is not equal to another shape object.

## Function Prototype

```cpp
bool operator!=(const Shape &rht) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|rht|Input|Another shape object.|

## Return Value

**true**: not equal; **false**: equal.

## Constraints

None

## Example

```cpp
Shape shape0({3, 256, 256});
Shape shape1({1, 3, 256, 256});
auto is_diff_shape = shape0 != shape1; // The return value is true (not equal).
```
