# AddAutoMappingSubgraphIOIndexFunc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:23:22.365Z pushedAt=2026-10-15T03:48:04.693Z -->

## Function

Registers the auto mapping function for a specific network type.

## Function Prototype

```cpp
void AddAutoMappingSubgraphIOIndexFunc(domi::FrameworkType framework, AutoMappingSubgraphIOIndexFunc fun)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|framework|Input|Network type. For the definition of the **FrameworkType** type, see **FrameworkType**.|
|fun|Input|Auto mapping input/output function. For the function type, see **AutoMappingSubgraphIndex**.|

## Return Value

None

## Exception Handling

None

## Constraints

None
