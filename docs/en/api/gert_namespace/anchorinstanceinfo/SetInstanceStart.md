# SetInstanceStart

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:27:02.500Z pushedAt=2026-10-15T03:48:04.818Z -->

## Function

Sets the start index of the first instantiated instance of the current input/output **Anchor**.

## Function Prototype

```cpp
void SetInstanceStart(const uint32_t instance_start)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|instance_start|Input|Index of the first instantiated **Anchor**.|

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
  size_t input_index = ir_index_to_instance_index_pair_map[i].first; // Obtain the actual input index corresponding to the operator IR input after statistics.
  ins_info->SetInstanceStart(input_index); // Save the information to the AnchorInstanceInfo object corresponding to the IR input.
}
```
