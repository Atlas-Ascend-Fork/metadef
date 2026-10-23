# SetPlacement

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:59:29.700Z pushedAt=2026-10-15T03:48:04.754Z -->

## Function

Sets the location where the tensor data is stored.

## Function Prototype

```cpp
graphStatus SetPlacement(const ge::Placement &placement)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|placement|Input|Value of the data address to be set. The enumeration values are defined as follows: enum Placement {  kPlacementHost = 0,   // host data addr  kPlacementDevice = 1, // device data addr};|

## Return Value

**graphStatus** type: Returns **GRAPH_SUCCESS** on success; otherwise, returns **GRAPH_FAILED**.

## Exception Handling

None

## Constraints

None
