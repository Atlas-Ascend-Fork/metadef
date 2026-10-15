# AutoMappingSubgraphIndex

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:39:24.570Z pushedAt=2026-10-15T03:48:04.720Z -->

## Function

Sets the mapping between the inputs and outputs of a subgraph and the corresponding parent node inputs and outputs in the main graph.

## Function Prototype

```cpp
Status AutoMappingSubgraphIndex(const ge::Graph &graph,
const std::function<int32_t(int32_t data_index)> &input,
const std::function<int32_t(int32_t netoutput_index)> &output)
Status AutoMappingSubgraphIndex(const ge::Graph &graph,
const std::function<Status(int32_t data_index, int32_t &parent_input_index)> &input,
const std::function<Status(int32_t netoutput_index, int32_t &parent_output_index)> &output)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|graph|Input|Subgraph object.|
|input|Input|Input mapping function.|
|output|Input|Output mapping function.|

## Constraints

None
