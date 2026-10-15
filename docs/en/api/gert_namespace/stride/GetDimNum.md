# GetDimNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:07:32.782Z pushedAt=2026-10-15T03:48:05.014Z -->

## Function

Obtains the number of dimensions of the **Stride** object.

## Function Prototype

```cpp
size_t GetDimNum() const
```

## Parameters

None

## Return Value

Number of dimensions of the **Stride** object.

## Constraints

None

## Example

```cpp
Stride stride0({3, 256, 256});
auto dim_num = stride0.GetDimNum(); // 3
```
