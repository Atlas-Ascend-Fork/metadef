# operator==

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:53:45.933Z pushedAt=2026-10-15T03:48:04.879Z -->

## Function

Determines whether this dimension expansion rule object is consistent with another object.

## Function Prototype

```cpp
bool operator==(const ExpandDimsType &other) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|other|Input|Another dimension expansion rule object.|

## Return Value

**true** indicates that they are consistent, and **false** indicates that they are inconsistent.

## Constraints

None

## Example

```cpp
ExpandDimsType type1("1001");
ExpandDimsType type2("1001");
bool is_same_type = type1 == type2; // true
```
