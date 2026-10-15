# GetSyncResInfos

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:48:47.751Z pushedAt=2026-10-15T03:48:04.868Z -->

## Function

Returns all synchronous resource information (a list of **SyncResInfo**) saved in the current object, for querying or external use.

## Function Prototype

```cpp
std::vector<SyncResInfo> GetSyncResInfos() const
```

## Parameters

None

## Return Value

Returns all synchronous resource information saved in the current object (a list of [SyncResInfo](../SyncResInfo.md)).

## Constraints

None

## Example

```cpp
std::vector<SyncResInfo> GetSyncResInfos(ExeResGenerationContext* context) {
  std::vector<SyncResInfo> syncResInfoList = context->GetSyncResInfos();
  ...
}
```
