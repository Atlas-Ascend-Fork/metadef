# SetNodeName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:38:31.803Z pushedAt=2026-10-15T03:48:04.846Z -->

## Function

Sets the name of the operator corresponding to this **ComputeNodeInfo**.

## Function Prototype

```cpp
void SetNodeName(const ge::char_t *node_name)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|node_name|Input|Name of the operator.|

## Return Value

None

## Constraints

None

## Example

```cpp
compute_node_info->SetNodeName("Conv2d");
```
