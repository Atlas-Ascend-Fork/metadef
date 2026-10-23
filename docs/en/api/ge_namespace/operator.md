# operator==

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:18:01.110Z pushedAt=2026-10-15T03:48:04.683Z -->

## Function

Checks whether this **Stride** object is equal to another **Stride** object. Two **Stride** objects are considered equal if they have the same number of dimensions and the stride value of each dimension is equal.

## Function Prototype

```cpp
bool operator==(const Stride &rht) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|rht|Input|Another **Stride** object.|

## Return Value

**true**: equal; **false**: not equal.

## Constraints

None

## Example

```cpp
Stride stride0({3, 256, 256});
Stride stride1({1, 3, 256, 256});
auto is_same_shape = stride0 == stride1; // The return value is false, indicating that they are not equal.
```
