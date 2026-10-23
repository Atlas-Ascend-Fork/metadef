# SetSyncResInfos

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:50:53.296Z pushedAt=2026-10-15T03:48:04.873Z -->

## Function

Sets the incoming synchronization resource information list (**sync\_info\_vec**) to the current object to configure the synchronization resource behavior during graph execution.

## Function Prototype

```cpp
ge::graphStatus SetSyncResInfos(std::vector<SyncResInfo> &sync_info_vec) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|sync_info_vec|Input|Synchronization resource information list, which is of the **std::vector\<SyncResInfo>** type.|

## Return Value

Returns the [graphStatus](../../ge_namespace/ge-graphStatus.md) status code.

## Constraints

None

## Example

```cpp
ge::graphStatus SetSyncResInfos(ExeResGenerationContext* context) {
  std::vector<SyncResInfo> sync_info_vec;
  ge::graphStatus status= context->SetSyncResInfos(sync_info_vec);
  ...
}
```
