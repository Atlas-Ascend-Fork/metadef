# AutoMappingSubgraphIOIndexFuncRegister

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:05:07.664Z pushedAt=2026-10-15T03:48:04.669Z -->

## Function

A wrapper of the **FrameworkRegistry** class. It registers the mapping function by calling the **AddAutoMappingSubgraphIOIndexFunc** function of the **FrameworkRegistry** class through the class constructor.

## Function Prototype

```cpp
AutoMappingSubgraphIOIndexFuncRegister(domi::FrameworkType framework, AutoMappingSubgraphIOIndexFunc fun)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|framework|Input|Network type. For the definition of the **FrameworkType** type, see **FrameworkType**.|
|fun|Input|Automatic mapping input/output function. For the function type, see **AutoMappingSubgraphIndex**.|

## Return Value

None

## Exception Handling

None

## Constraints

None
