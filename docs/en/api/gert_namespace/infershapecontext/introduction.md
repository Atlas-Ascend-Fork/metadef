# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:17:09.401Z pushedAt=2026-10-15T03:48:04.915Z -->

**InferShapeContext** inherits from **ExtendedKernelContext** and is a context class used for shape inference. The main purpose of this class is to provide the necessary input/output shape and input tensor access APIs during the process of inferring operator output shapes. For operators whose shape inference depends on input tensor values (for example, **Slice** and **Pad**), this class provides APIs such as **GetInputTensor** to obtain the actual input data.

The inheritance relationship of **InferShapeContext** is as follows:

![infershape_context](../../figures/infershape_context.png)

## Header File to Include

```cpp
#include <infer_shape_context.h>
```
