# SetWorkspaceBytes

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:50:52.759Z pushedAt=2026-10-15T03:48:04.874Z -->

## Function

Sets the workspace size.

## Function Prototype

```cpp
void SetWorkspaceBytes(const std::vector<int64_t> &workspace_bytes) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|workspace_bytes|Input|Workspace size configuration information.|

## Return Value

None

## Constraints

None

## Example

```cpp
void SetWorkspaceBytes(ExeResGenerationContext* context) {
  std::vector<int64_t> workspace_bytes;
  context->SetWorkspaceBytes(workspace_bytes);
  // ...
}
```
