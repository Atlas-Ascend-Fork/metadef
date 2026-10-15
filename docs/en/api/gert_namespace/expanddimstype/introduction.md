# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:53:02.046Z pushedAt=2026-10-15T03:48:04.878Z -->

The **ExpandDimsType** class describes the dimension expansion rule based on the shape after dimension expansion.

Dimension expansion means adding one or more dimensions to the original shape. For example, if the original shape has two axes, the shape after adding two dimensions between the two axes is [2, 1, 1, 2]. In the shape after dimension expansion, axes 0 and 3 are called original axes, and axes 1 and 2 are called expanded axes.

The **ExpandDimsType** class describes the dimension expansion rule using "1" and "0", where "1" indicates that the current axis is an expanded axis and "0" indicates that the current axis is an original axis. From left to right, they represent the source of each axis in the current shape. For example:

**Table 1** Dimension expansion rule description

|Dimension Expansion Rule|Shape Before Dimension Expansion|Shape After Dimension Expansion|
|--|--|--|
|0110|[2, 2]|[2, 1, 1, 2]|
|100|[2, 3]|[1, 2, 3]|
|1000|[2, 3]|The dimension expansion rule does not match the shape before dimension expansion. The rule specifies three original axes, but the original shape has only two axes, so dimension expansion reports an error.|

## Header Files to Include

```cpp
#include <expand_dims_type.h>
```
