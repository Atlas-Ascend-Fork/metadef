# SetNodeType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:38:55.876Z pushedAt=2026-10-15T03:48:04.847Z -->

## Function

Sets the operator type.

## Function Prototype

```cpp
void SetNodeType(const ge::char_t *node_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**node_type**|Input|Operator type.|

## Return Value

None

## Constraints

None

## Example

```cpp
compute_node_info.SetNodeType("Const");
```
