# SetInstantiationNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:27:38.506Z pushedAt=2026-10-15T03:48:04.819Z -->

## Function

Sets the number of instances for which the current input/output is instantiated.

## Function Prototype

```cpp
void SetInstantiationNum(const uint32_t instantiation_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**instantiation_num**|Input|Number of instances to be instantiated.|

## Return Value

None

## Constraints

None

## Example

```cpp
const auto &ir_inputs = node->GetOpDesc()->GetIrInputs();  // All inputs defined by the operator IR prototype.
for (size_t i = 0; i < ir_inputs.size(); ++i) {
  auto ins_info = compute_node_info.MutableInputInstanceInfo(i);  // Obtain the AnchorInstanceInfo object corresponding to the i-th IR input.
  GE_ASSERT_NOTNULL(ins_info);
  size_t instance_num = ir_index_to_instance_index_pair_map[i].second; // Obtain the actual number of inputs corresponding to the operator IR input after statistics.
  ins_info->SetInstantiationNum(instance_num); // Save the information to the AnchorInstanceInfo object corresponding to the IR input.
}
```
