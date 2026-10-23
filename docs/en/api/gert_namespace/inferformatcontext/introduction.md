# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:11:50.289Z pushedAt=2026-10-15T03:48:04.907Z -->

**InferFormatContext** inherits from **ExtendedKernelContext** and is a context class used for format inference. The main purpose of this class is to provide the necessary input/output format, input/output shape, and input tensor access APIs during the process of inferring the output format of an operator. **InferFormatContext** is the input parameter of the format inference function. For details about the format inference function, see [InferFormat](../opimplregisterv2/InferFormat.md).

The inheritance relationship of **InferFormatContext** is as follows:

![](../../figures/inferformat_context.png)

## Header File to Include

```cpp
#include <infer_format_context.h>
```
