# SyncResInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:21:59.326Z pushedAt=2026-10-15T03:48:04.785Z -->

```cpp
/*
 * Input parameters:
 *  type: Resource type, which identifies the category of the synchronization resource (such as event synchronization, memory synchronization, and computation synchronization).
 *  name: Resource name (or type name). If reuse_key is empty, this field is used as the reuse key for resource reuse.
 *  reuse_key: Resource reuse key. Resources with the same key are reused (shared) to optimize resource allocation and reduce redundant creation.
 *  required: Whether the resource is required. If true, the resource must be allocated successfully; otherwise, operator validation fails.
 *
 * Output parameters:
 *  is_valid: Resource allocation validity status. true indicates that the resource has been allocated successfully and is available; false indicates allocation failure or that the resource is not allocated.
 *  sync_res_id: ID of the successfully allocated synchronization resource, used to reference the resource in subsequent execution flows (such as event synchronization and inter-stream dependencies).
 */
struct SyncResInfo {
  SyncResType type;                  // Resource type (such as event and memory synchronization)
  ge::AscendString name;             // Resource name (or type name). If reuse_key is empty, it is used as the reuse key.
  ge::AscendString reuse_key;        // Resource reuse key. Resources with the same key are reused.
  bool required{true};               // Whether the resource is required.
  bool is_valid{false};              // Resource allocation validity status.
  int32_t sync_res_id{-1};           // ID of the successfully allocated synchronization resource, referenced in the execution flow.
};
```
