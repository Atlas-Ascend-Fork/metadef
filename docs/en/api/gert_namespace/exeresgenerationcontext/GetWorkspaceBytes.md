# GetWorkspaceBytes

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:48:47.827Z pushedAt=2026-10-15T03:48:04.868Z -->

## Function

Obtains the workspace size.

## Function Prototype

```cpp
std::vector<int64_t> GetWorkspaceBytes() const
```

## Parameters

None

## Return Value

Returns the workspace size configuration information.

## Constraints

None

## Example

```cpp
std::vector<int64_t> GetWorkspaceBytes(ExeResGenerationContext* context) {
  std::vector<int64_t> workspaceList = context->GetWorkspaceBytes();
  // ...
}
```
