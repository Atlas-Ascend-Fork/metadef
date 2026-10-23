# ParseSubgraphPostFn

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:47:17.996Z pushedAt=2026-10-15T03:48:04.736Z -->

## Function

Registers the function implementation that maps the input/output nodes in the operator's subgraph to the operator's inputs and outputs, based on the operator type.

## Function Prototype

> [!NOTE] Note
> APIs with the string data type will be deprecated in later versions. Use APIs with a non-string data type instead.

```cpp
OpRegistrationData &ParseSubgraphPostFn(const ParseSubgraphFunc &subgraph_post_fn)
OpRegistrationData &ParseSubgraphPostFn(const ParseSubgraphFuncV2 &subgraph_post_fn)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|subgraph_post_fn|Input|Function object that maps the input/output nodes in the subgraph to the operator's inputs and outputs. For details, see **.**|

## Constraints

None

## Callback Function ParseSubgraphFuncV2

The user defines and implements the **ParseSubgraphFuncV2** function to resolve the mapping between the input/output nodes in the subgraph and the input/output of the operator. The callback function prototype is defined as follows:

```cpp
Status ParseSubgraphFuncV2(const ge::AscendString &subgraph_name, const ge::Graph &graph)
```

**Table 1** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|subgraph_name|Input|Subgraph name.|
|graph|Output|Constructed subgraph.|
