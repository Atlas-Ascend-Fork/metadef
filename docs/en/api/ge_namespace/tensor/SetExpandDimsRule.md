# SetExpandDimsRule

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:57:20.437Z pushedAt=2026-10-15T03:48:04.751Z -->

## Function

Sets the dimension expansion rule for a tensor.

Dimension expansion means adding one or more dimensions to the original shape. For example, if the original shape\[2,2\] has two axes, then after expanding two dimensions between the two axes, the shape becomes \[2,1,1,2\]. In the shape after dimension expansion, axes 0 and 3 are called original axes, and axes 1 and 2 are called expanded axes.

The dimension expansion rule is described by 1 and 0, where 1 indicates that the current axis is an expanded axis and 0 indicates that the current axis is an original axis. From left to right, they represent the source of each axis in the current shape. For example:

**Table 1**  Dimension expansion rule examples

|Dimension Expansion Rule|Shape Before Dimension Expansion|Shape After Dimension Expansion|
|--|--|--|
|0110|[2, 2]|[2, 1, 1, 2]|
|100|[2, 3]|[1, 2, 3]|
|1000|[2, 3]|The dimension expansion rule does not match the shape before dimension expansion. The rule specifies three original axes, but the original shape has only two axes, so dimension expansion reports an error.|

## Function Prototype

```cpp
graphStatus SetExpandDimsRule(const AscendString &expand_dims_rule)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|expand_dims_rule|Input|**expand_dims_rule** dimension expansion rule to be set, expressed as a string to represent dimension expansion.|

## Return Value

**graphStatus** type: Returns **GRAPH\_SUCCESS** on success; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

None
