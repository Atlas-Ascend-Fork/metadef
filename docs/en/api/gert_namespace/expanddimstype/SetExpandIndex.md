# SetExpandIndex

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:53:50.566Z pushedAt=2026-10-15T03:48:04.881Z -->

## Function

Sets the **index**-th axis as an expanded dimension axis.

## Function Prototype

```cpp
void SetExpandIndex(const AxisIndex index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|The **index**-th axis is an expanded dimension axis. **using AxisIndex = uint64_t;**|

## Return Value

None

## Constraints

None

## Example

```cpp
ExpandDimsType type1("1001");
type1.SetExpandIndex(1); // Dimension expansion rule mask_=1101.
```
