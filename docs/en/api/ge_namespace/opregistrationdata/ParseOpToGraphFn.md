# ParseOpToGraphFn

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T01:46:21.889Z pushedAt=2026-10-15T03:48:04.734Z -->

## Function

Registers a function that implements one-to-many subgraph mapping for an operator, that is, mapping an operator to multiple operators.

## Function Prototype

```cpp
OpRegistrationData &ParseOpToGraphFn(const ParseOpToGraphFunc &parse_op_to_graph_fn)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|parse_op_to_graph_fn|Input|Function that implements one-to-many operator mapping and performs subgraph construction. See the callback function ParseOpToGraphFunc.|

## Constraints

When implementing one-to-many subgraph mapping, during plugin registration, you must first map the operator in the original framework to the **PartitionedCall** operator on the AI processor, and use the **SetAttr** API in the [ParseParamsByOperatorFn](ParseParamsByOperatorFn.md) function to set **original\_type**.

For an implementation example, see [Example](#example).

## Callback Function ParseOpToGraphFunc

Users customize and implement the **ParseOpToGraphFunc** function to construct a one-to-many subgraph through IR model construction. For details about graph construction, see *[Graph Development](https://gitcode.com/cann/ge/blob/master/docs/zh/user_guides/graph_dev/README.md)*.

The callback function prototype is defined as follows:

```cpp
Status  ParseOpToGraphFunc(const ge::Operator &op,  ge::Graph &graph)
```

**Table 1** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op|Input|Data structure of the **PartitionedCall** operator, which is an **Operator** class object.|
|graph|Output|Constructed subgraph.|

The input and output relationships of the subgraph are constructed as follows:

- Input: Add a **Data** node as the identifier. The **index** attribute of the **Data** node indicates the *index*-th input edge of the original node.
- Output: Set through the **Graph::SetOutputs\(\)** API. The input parameter of this API is **std::vector<std::pair<Operator, std::vector<size\_t\>\>\>**, and the output edges are connected in the order in which the outputs are set.

## Example

Take converting the Add operator into AddN+Abs as an example.

The following shows an example of implementing the mapping function from the Add operator to the PartitionedCall operator:

```cpp
Status ParseParams(const ge::Operator &op_src, ge::Operator& op_dest)
{
    ...
    op_dest.SetAttr("original_type", "ai.onnx::11::Add");
}
```

An example of the one-to-many subgraph constructor implementation is as follows:

```cpp
static Status ParseOpToGraph(const Operator &op, Graph &graph) {
  auto data_0 = op::Data().set_attr_index(0);
  auto data_1 = op::Data().set_attr_index(1);
  auto addn = op::AddN("addn_sum").create_dynamic_input_x(2)
      .set_dynamic_input_x(0, data_0)
      .set_dynamic_input_x(1, data_1)
      .set_attr_N(2);
  auto abs = op::Abs("abs_sum").set_input_x(addn);
  std::vector<Operator> inputs{data_0, data_1};
  std::vector<std::pair<Operator, std::vector<size_t>>> output_indexs;
  output_indexs.emplace_back(abs, vector<std::size_t>{0});
  graph.SetInputs(inputs).SetOutputs(output_indexs);
  return domi::SUCCESS;
}
```

Perform registration:

```cpp
REGISTER_CUSTOM_OP("PartitionedCall")
.FrameworkType(xx)
.OriginOpType(xx)
.ParseParamsByOperatorFn(ParseParams)
.ParseOpToGraphFn(ParseOpToGraph)
.ImplyType(ImplyType::TVM);
```

The following figure shows an example of mapping the Add operator to a one-to-many subgraph.

![](../../figures/one_to_many_convert.png)
