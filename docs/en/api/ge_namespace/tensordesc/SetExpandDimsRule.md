# SetExpandDimsRule

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:08:21.461Z pushedAt=2026-10-15T03:48:04.767Z -->

## Function

Sets the dimension expansion rule. Dimension expansion refers to adding one or more dimensions to the original shape. For example, if the original shape\[2,2\] has two axes, then the shape after adding two dimensions between the two axes is \[2,1,1,2\]. After dimension expansion, axes 0 and 3 of the shape are called original axes, and axes 1 and 2 are called expanded axes.

The dimension expansion rule is described using 1 and 0, where 1 indicates that the current axis is an expanded axis and 0 indicates that the current axis is an original axis. From left to right, each value represents the source of the corresponding axis in the current shape. For example:

**Table 1**  Dimension expansion rule examples

|Dimension Expansion Rule|Shape Before Dimension Expansion|Shape After Dimension Expansion|
|--|--|--|
|0110|[2, 2]|[2, 1, 1, 2]|
|100|[2, 3]|[1, 2, 3]|
|1000|[2, 3]|The dimension expansion rule does not match the shape before dimension expansion. The rule specifies three original axes, but the original shape has only two axes, so dimension expansion reports an error.|

The GE framework provides the capability to specify the runtime format (the runtime format of the input and output nodes of the entire network) to reduce unnecessary format conversion overhead and achieve greater performance gains. When developers specify the runtime format themselves, there are two ways to set the corresponding runtime shape:

- The developer specifies the runtime shape.
- **The framework derives the runtime shape. In this case, if the original shape has fewer dimensions than the dimensions expressed by the original format, the dimension expansion rule must be set synchronously through this API, and the framework sets the runtime shape based on this dimension expansion rule.**

## Function Prototype

```cpp
void SetExpandDimsRule(const AscendString &expand_dims_rule)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|expand_dims_rule|Input|Dimension expansion rule to be set. Type: **AscendString**. Example: The original shape is [2, 3], the original format is NCHW, and the dimension of the original shape (2) is smaller than the dimension of NCHW (4), so a dimension expansion rule needs to be set. For example, if the dimension expansion rule is set to "0110", the shape after dimension expansion is [2, 1, 1, 3].|

## Return Value

None

## Exception Handling

None

## Constraints

None
