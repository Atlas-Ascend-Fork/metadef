# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:41:47.559Z pushedAt=2026-10-15T03:48:04.959Z -->

Used to build a general **KernelContext** object, which serves as the input context for the actual execution phase of the operator host implementation.

The inheritance diagram of **OpKernelContextBuilder** is as follows:

![opkernel_context_builder](../../figures/opkernel_context_builder.png)

> [!NOTE] Note
> This class inherits from the **OpContextBuilderBase** class. Before calling **Build** to construct the **ContextHolder** object, you need to call the **OpType**, **OpName**, **IONum** or **IOInstanceNum**, and **AppendAttr** APIs of **OpContextBuilderBase** to set the operator type, name, number of inputs and outputs, and operator attributes, respectively.

## Header File to Include

```cpp
#include "base/context_builder/op_kernel_run_context_builder.h"
```
