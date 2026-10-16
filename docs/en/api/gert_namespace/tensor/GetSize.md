# GetSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:14:25.646Z pushedAt=2026-10-15T03:48:05.028Z -->

## Function

Obtains the memory size of tensor data.

## Function Prototype

```cpp
size_t GetSize() const
```

## Parameters

None

## Return Value

Memory size, in bytes.

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
Tensor t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
auto td_size = t.GetSize(); // 1*2*3*sizeof(float) = 24;
```
