# GetFullSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:52:43.797Z pushedAt=2026-10-15T03:48:04.877Z -->

## Function

Obtains the dimension count after dimension expansion.

## Function Prototype

```cpp
AxisIndex GetFullSize() const
```

## Parameters

None

## Return Value

Returns the length of the dimension expansion rule, that is, the number of dimensions described by the dimension expansion rule.

## Constraints

None

## Example

```cpp
ExpandDimsType type1("1001");
auto dim_num = type1.GetFullSize(); // dim_num=4
```
