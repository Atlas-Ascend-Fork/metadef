# GetParseSubgraphPostFn

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:44:05.303Z pushedAt=2026-10-15T03:48:04.730Z -->

## Function

Obtains the function object that implements the correspondence between the input/output nodes in the subgraph registered for an operator and the operator's inputs/outputs, based on the operator type.

## Function Prototype

> [!NOTE] Note
> The GetParseSubgraphPostFn\(\) function will be deprecated in later versions. It is recommended to use the GetParseSubgraphPostFn\(ParseSubgraphFuncV2 &func\) function instead.

- **ParseSubgraphFunc GetParseSubgraphPostFn\(\) const**

  This function returns a function object of the **ParseSubgraphFunc** type. The declaration of the ParseSubgraphFunc function is as follows:

  ```cpp
  using ParseSubgraphFunc = std::function<Status(const std::string &subgraph_name, const ge::Graph &graph)>
  ```

- **Status GetParseSubgraphPostFn\(ParseSubgraphFuncV2 &func\) const**

  This function returns a function object of the **ParseSubgraphFuncV2** type. The declaration of the ParseSubgraphFuncV2 function is as follows:

  ```cpp
  using ParseSubgraphFuncV2 = std::function<Status(const ge::AscendString &subgraph_name, const ge::Graph &graph)>
  ```

## Parameters

- GetParseSubgraphPostFn\(\) function

  None

- GetParseSubgraphPostFn\(ParseSubgraphFuncV2 &func\) function

  |Parameter|Input/Output|Description|
  |--|--|--|
  |func|Output|Function object that implements the correspondence between the input/output nodes in the subgraph registered for an operator and the operator's inputs/outputs.|

## Constraints

None
