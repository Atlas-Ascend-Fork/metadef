# GetAddr

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:19:55.730Z pushedAt=2026-10-15T03:48:05.042Z -->

## Function

Obtains the address of the tensor data. If the **manager** function exists, the address is provided by the **manager** function.

## Function Prototype

```cpp
TensorAddress GetAddr() const
```

## Parameters

None

## Return Value

Tensor address.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
auto addr = td.GetAddr(); // 0x10
```
