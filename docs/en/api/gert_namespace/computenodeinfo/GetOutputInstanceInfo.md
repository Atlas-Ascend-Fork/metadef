# GetOutputInstanceInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:35:24.769Z pushedAt=2026-10-15T03:48:04.840Z -->

## Function

Obtains the corresponding instantiated object based on the output index in the operator IR prototype.

## Function Prototype

```cpp
const AnchorInstanceInfo *GetOutputInstanceInfo(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Output index defined in the operator IR prototype, starting from 0.|

## Return Value

Returns the address of the **const**-type instantiated object.

## Constraints

None

## Example

```cpp
for (size_t i = 0; i < ir_outputs.size(); ++i) {
  auto ins_info = compute_node_info.GetOutputInstanceInfo(i);
  ...
}
```
