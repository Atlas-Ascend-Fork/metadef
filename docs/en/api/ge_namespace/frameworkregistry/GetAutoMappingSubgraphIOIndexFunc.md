# GetAutoMappingSubgraphIOIndexFunc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:24:11.822Z pushedAt=2026-10-15T03:48:04.695Z -->

## Function

Obtains the registered auto mapping function based on the network type.

## Function Prototype

```cpp
AutoMappingSubgraphIOIndexFunc GetAutoMappingSubgraphIOIndexFunc(domi::FrameworkType framework)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|framework|Input|Network type. For the definition of the **FrameworkType** type, see **FrameworkType**.|

## Return Value

**AutoMappingSubgraphIOIndexFunc**: Auto mapping input/output function. For details about the function type, see [AutoMappingSubgraphIndex](../opregistrationdata/AutoMappingSubgraphIndex.md).

## Exception Handling

None

## Constraints

None
