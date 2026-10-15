# StreamInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:21:33.655Z pushedAt=2026-10-15T03:48:04.784Z -->

```cpp
/*
 * Input parameters:
 *  name: Resource name (or type name). If reuse_key is empty, this field is used as the reuse key for resource reuse.
 *  reuse_key: Resource reuse key. Resources with the same key are reused (shared) to optimize memory or compute resource allocation.
 *  depend_value_input_indices: List of dependent input value indices, indicating which input tensor values the creation or allocation of this resource depends on.
 *  required: Whether the resource is required. If true, the resource must be allocated successfully; otherwise, validation fails.
 *
 * Output parameters:
 *  is_valid: Resource allocation status flag. true indicates that the resource has been allocated successfully and is available; false indicates allocation failure or that the resource is not allocated.
 *  stream_id: Stream ID used for resource allocation, specifying the execution stream (such as a compute stream or memory stream) on which resource operations are performed.
 */
struct StreamInfo {
  ge::AscendString name;                           // Resource name (or type name).
  ge::AscendString reuse_key;                      // Resource reuse key (reused for the same key).
  std::vector<int64_t> depend_value_input_indices; // List of dependent input value indices.
  bool required{true};                             // Whether it is a required resource.
  bool is_valid{false};                            // Validity status of resource allocation.
  int64_t stream_id{-1};                           // Stream ID used for resource allocation.
};
```
