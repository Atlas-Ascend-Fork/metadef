# GetWorkspaceNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:47:30.127Z pushedAt=2026-10-15T03:48:05.096Z -->

## Function

Obtains the number of workspaces.

## Function Prototype

```cpp
size_t GetWorkspaceNum() const
```

## Parameters

None

## Return Value

Number of workspaces.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ws_num = context->GetWorkspaceNum();
  // ...
}
```
