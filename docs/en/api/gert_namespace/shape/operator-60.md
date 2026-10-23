# operator==

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:58:57.904Z pushedAt=2026-10-15T03:48:04.995Z -->

## Function

Checks whether this shape is equal to another shape object. Two shapes are considered equal if they have the same **dim num** and the values of **dim**s in **dim num** are equal.

## Function Prototype

```cpp
bool operator==(const Shape &rht) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|rht|Input|Another shape object.|

## Return Value

**true**: equal; **false**: not equal.

## Constraints

None

## Example

```cpp
Shape shape0({3, 256, 256});
Shape shape1({1, 3, 256, 256});
auto is_same_shape = shape0 == shape1; // The return value is false (not equal).
```
