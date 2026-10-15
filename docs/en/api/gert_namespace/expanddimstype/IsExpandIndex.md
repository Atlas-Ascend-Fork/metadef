# IsExpandIndex

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:53:12.446Z pushedAt=2026-10-15T03:48:04.879Z -->

## Function

Determines whether the specified index axis is an expanded dimension axis based on the expanded shape.

## Function Prototype

```cpp
bool IsExpandIndex(const AxisIndex index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the specified axis.|

## Return Value

- **true** indicates that the specified axis is an expanded dimension axis.
- **false** indicates that the specified axis is an original axis.

## Constraints

None

## Example

```cpp
ExpandDimsType type1("1001");
bool is_expand_index0 = type1.IsExpandIndex(0); // true
bool is_expand_index1 = type1.IsExpandIndex(1); // false
```
