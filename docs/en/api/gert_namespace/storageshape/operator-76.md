# operator!=

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:06:42.553Z pushedAt=2026-10-15T03:48:05.012Z -->

## Function

Checks whether the shapes are not equal.

## Function Prototype

```cpp
bool operator!=(const StorageShape &other) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|other|Input|Another shape.|

## Return Value

**true**: not equal; **false**: equal.

## Constraints

None

## Example

```cpp
StorageShape shape0({3, 256, 256}, {256, 256, 3});
StorageShape shape1({3, 256, 256}, {3, 256, 256});
bool is_diff_shape = shape0 != shape1; // true
```
