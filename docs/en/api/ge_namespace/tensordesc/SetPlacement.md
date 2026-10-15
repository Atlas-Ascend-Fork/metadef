# SetPlacement

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:11:07.435Z pushedAt=2026-10-15T03:48:04.771Z -->

## Function

Sets the data placement of a tensor.

## Function Prototype

```cpp
void SetPlacement(Placement placement)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**placement**|Input|Value of the data address to be set. The enumeration values are defined as follows: enum Placement {  kPlacementHost = 0,   // host data addr  kPlacementDevice = 1, // device data addr};|

## Return Value

None

## Exception Handling

None

## Constraints

None
