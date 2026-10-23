# GetAttachedStreamInfos

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:46:12.462Z pushedAt=2026-10-15T03:48:04.862Z -->

## Function

Returns the list of all **StreamInfo** objects bound to the current operator.

## Function Prototype

```cpp
std::vector<StreamInfo> GetAttachedStreamInfos() const
```

## Parameters

None

## Return Value

Returns the list of all [StreamInfo](../StreamInfo.md) objects bound to the current operator.

## Constraints

None

## Example

```cpp
std::vector<StreamInfo> GetAttachedStreamInfos(ExeResGenerationContext* context) {
  std::vector<StreamInfo> streamInfoList = context->GetAttachedStreamInfos();
  ...
}
```
