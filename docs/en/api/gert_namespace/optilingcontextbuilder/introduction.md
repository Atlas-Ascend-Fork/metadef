# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:44:33.182Z pushedAt=2026-10-15T03:48:04.965Z -->

**OpTilingContextBuilder** is used to build a **TilingContext**. The constructed context serves as an input parameter during operator tiling computation to obtain necessary data such as operator inputs and outputs. After the tiling computation is complete, the results are written back to the context.

The inheritance relationship of **OpTilingContextBuilder** is as follows:

![optiling_context_builder](../../figures/optiling_context_builder.png)

The usage steps are as follows:

1. Construct a **ContextHolder**.

   Call the **OpTilingContextBuilder** API and pass in the corresponding input data, such as the input **Tensor** and **PlatformInfo**, and finally call the **Build\(\)** API to construct a **ContextHolder<TilingContext\>** object.

2. Obtain the **TilingContext**.

   Call the **GetContext** API through the **ContextHolder** to obtain the **TilingContext**.

3. Call the operator tiling implementation function **TilingKernelFunc**, passing the **TilingContext** as a function input parameter to complete the tiling computation, and the operator writes the computed output results.
4. Obtain the tiling computation results through the **TilingContext** API.
5. Release **ContextHolder** as needed. After the release is complete, the data pointers in the **TilingContext** constructed by **Build** are all invalid.

> [!NOTE] Note
> This class inherits from the **OpContextBuilderBase** class. Before **Build** constructs the **ContextHolder** object, you need to call the **OpType**, **OpName**, **IONum** or **IOInstanceNum**, and **AppendAttr** APIs of **OpContextBuilderBase** to set the operator type, name, number of inputs and outputs, and operator attributes, respectively.

## Header File to Include

```cpp
#include "base/context_builder/op_tiling_context_builder.h"
```
