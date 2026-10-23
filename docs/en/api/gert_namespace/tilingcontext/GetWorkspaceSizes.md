# GetWorkspaceSizes

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:47:35.920Z pushedAt=2026-10-15T03:48:05.096Z -->

## Function

Obtains the pointer to the workspace sizes, where the workspace sizes are measured in bytes.

## Function Prototype

```cpp
size_t *GetWorkspaceSizes(const size_t workspace_count)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|workspace_count|Input|Number of workspaces. The value must not exceed the number of workspaces returned by **GetWorkspaceNum**. If it is exceeded, a null pointer is returned.|

## Return Value

Pointer to the workspace sizes.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
    auto ws = context->GetWorkspaceSizes(5);
    if (ws == nullptr) {
        return ge::GRAPH_FAILED;
    }
    // ...
}
```
