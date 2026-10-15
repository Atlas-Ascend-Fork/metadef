# operator!=

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:08:24.932Z pushedAt=2026-10-15T03:48:05.017Z -->

## Function

Checks whether this stride object is not equal to another stride object.

## Function Prototype

```cpp
bool operator!=(const Stride &rht) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|rht|Input|Another stride object.|

## Return Value

**true**: not equal; **false**: equal.

## Constraints

None

## Example

```cpp
Stride stride0({3, 256, 256});
Stride stride1({1, 3, 256, 256});
auto is_diff_shape = stride0 != stride1; // The return value is true (not equal).
```
