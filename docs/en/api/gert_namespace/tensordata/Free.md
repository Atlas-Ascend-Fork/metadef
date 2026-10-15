# Free

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:19:53.695Z pushedAt=2026-10-15T03:48:05.042Z -->

## Function

Releases the tensor.

## Function Prototype

```cpp
ge::graphStatus Free()
```

## Parameters

None

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success; otherwise, returns the status code returned by the **manager** function.

For the definition of the **ge::graphStatus** type, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
td.Free();
```
