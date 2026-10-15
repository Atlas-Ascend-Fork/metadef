# MutableInputInstanceInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:37:21.665Z pushedAt=2026-10-15T03:48:04.843Z -->

## Function

Obtains the corresponding instantiated object based on the input index in the operator IR prototype.

## Function Prototype

```cpp
AnchorInstanceInfo *MutableInputInstanceInfo(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index defined in the operator IR prototype, counting from 0.|

## Return Value

Returns the address of the instantiated object. The returned object is non-**const**.

## Constraints

None

## Example

```cpp
for (size_t i = 0; i < ir_inputs.size(); ++i) {
  auto ins_info = compute_node_info.MutableInputInstanceInfo(i);
  ...
}
```
