# GetSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:20:46.236Z pushedAt=2026-10-15T03:48:05.044Z -->

## Function

Obtains the memory size of the tensor data.

## Function Prototype

```cpp
size_t GetSize() const
```

## Parameters

None

## Return Value

Memory size occupied by the tensor, in bytes.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
auto td_size = td.GetSize(); // 100U
```
