# CalcSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:32:20.037Z pushedAt=2026-10-15T03:48:04.833Z -->

## Function

Calculates the size of the memory space that needs to be pre-allocated for the **ComputeNodeInfo** corresponding to the operator.

The memory space of **ComputeNodeInfo** is flat. The memory stores, in sequence, the data members of **ComputeNodeInfo** itself, the anchor information for the number of inputs defined in the operator's IR prototype definition, the tensor description information at the compilation stage for the actual number of inputs and outputs, and the attribute information. The calculation result of this function does not include the memory space occupied by the attribute information.

## Function Prototype

```cpp
static ge::graphStatus CalcSize(const size_t ir_inputs_num, const size_t inputs_num, const size_t outputs_num, size_t &total_size)
static ge::graphStatus CalcSize(const size_t ir_inputs_num, const size_t ir_outputs_num, const size_t inputs_num, const size_t outputs_num, size_t &total_size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**ir_inputs_num**|Input|Number of inputs defined in the operator's IR prototype definition.|
|**ir_outputs_num**|Input|Number of outputs defined in the operator's IR prototype definition.|
|**inputs_num**|Input|Actual number of inputs of the operator.|
|**outputs_num**|Input|Actual number of outputs of the operator.|
|**total_size**|Output|Total size of the memory to be pre-allocated for **ComputeNodeInfo** and related information, excluding the memory size of **RuntimeAttrs**.|

## Return Value

The return value is of the **graphStatus** type (**uint32\_t**). Its different statuses and values are described as follows:

|Status|Value|Description|
|--|--|--|
|ge::GRAPH_SUCCESS|0|Execution succeeded.|
|ge::GRAPH_PARAM_INVALID|50331649|Execution failed. The parameter is invalid and failed validation.|

## Constraints

None

## Example

```cpp
auto ir_input_num = node->GetOpDesc()->GetIrInputs().size();
auto input_num = node->GetInDataNodesAndAnchors().size();
auto output_num = node->GetAllOutDataAnchorsSize();
GE_ASSERT_SUCCESS(ComputeNodeInfo::CalcSize(ir_input_num, input_num, output_num, total_size));
```
