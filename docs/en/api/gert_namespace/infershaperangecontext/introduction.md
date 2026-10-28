# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:21:23.064Z pushedAt=2026-10-15T03:48:04.922Z -->

**InferShapeRangeContext** inherits from **ExtendedKernelContext** and is mainly used to obtain the input and output **ShapeRange** and the input **TensorRange** of an operator. **ShapeRange** and **TensorRange** are specialization types of the **Range<T\>** template, recording the upper and lower bounds of the operator's shape and tensor values. For some operators (for example, the **NonZero** operator), the specific output shape cannot be inferred during shape inference, and only the maximum shape can be estimated through the **ShapeRange** information.

The inheritance relationship of **InferShapeRangeContext** is as follows:

![infershaperange_context](../../figures/infershaperange_context.png)

## Header File to Include

```cpp
#include <infer_shape_range_context.h>
```
