# Init

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:36:22.175Z pushedAt=2026-10-15T03:48:04.841Z -->

## Function

Initializes the **ComputeNodeInfo** class.

## Function Prototype

```cpp
void Init(const size_t ir_inputs_num, const size_t inputs_num, const size_t outputs_num, const ge::char_t *node_name, const ge::char_t *node_type)
void Init(const size_t ir_inputs_num, const size_t ir_outputs_num, const size_t inputs_num, const size_t outputs_num, const size_t attr_size, const ge::char_t *node_name, const ge::char_t *node_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**ir_inputs_num**|Input|Number of inputs in the operator prototype.|
|**inputs_num**|Input|Actual number of operator inputs.|
|**outputs_num**|Input|Actual number of operator outputs.|
|**node_name**|Input|Node name.|
|**node_type**|Input|Node type (operator prototype name).|
|**ir_outputs_num**|Input|Number of outputs in the operator prototype.|
|**attr_size**|Input|Number of attributes.|

## Return Value

None

## Constraints

None

## Example

```cpp
auto ir_input_num = compute_node->GetOpDesc()->GetIrInputs().size();
auto inputs_num = compute_node->GetInDataNodesAndAnchors().size();
auto outputs_num = compute_node->GetOutDataNodesAndAnchors().size();
auto compute_node_info_holder = std::make_unique<uint8_t[]>(total_size);
auto compute_node_info = reinterpret_cast<ComputeNodeInfo *>(compute_node_info_holder.get());
compute_node_info->Init(ir_input_num, inputs_num, outputs_num, node_name, node_type);
```
