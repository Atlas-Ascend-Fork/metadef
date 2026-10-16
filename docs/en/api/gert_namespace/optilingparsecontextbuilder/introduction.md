# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:49:30.223Z pushedAt=2026-10-15T03:48:04.975Z -->

**OpTilingParseContextBuilder** is used to build **TilingParseContext**. The constructed context serves as input during the operator **TilingParse** computation to obtain the necessary operator input and output data. After the Parser computation is complete, the result is written back to the context.

The inheritance relationship of **OpTilingParseContextBuilder** is as follows:

![](../../figures/optilingparse_context_builder.png)

The usage steps are as follows:

1. Construct a **ContextHolder**.

   Call the **OpTilingParseContextBuilder** API, pass in the corresponding input data, such as the input **InputTensorDesc** and **CompiledJson**, and finally call the **Build\(\)** API to construct a **ContextHolder<TilingParseContext\>** object.

2. Obtain the **TilingParseContext**.

   Call the **GetContext** API through the **ContextHolder** to obtain the **TilingParseContext**.

3. Call the operator **TilingParser** function **TilingParserKernelFunc**, passing the **TilingParseContext** as the function input parameter, to complete the **TilingParser** computation and write the computed output result.
4. Obtain the **CompiledInfo** through the API of **TilingParseContext**.
5. Release **ContextHolder** as needed. After the release is complete, all data pointers in the **TilingParseContext** constructed by **Build** become invalid.

> [!NOTE] Note
> This class inherits from the **OpContextBuilderBase** class. Before **Build** constructs the **ContextHolder** object, call the **OpType**, **OpName**, **IONum** or **IOInstanceNum**, and **AppendAttr** APIs of **OpContextBuilderBase** to set the operator type, name, number of inputs and outputs, and operator attributes, respectively.

## Header File to Include

```cpp
#include "base/context_builder/op_tiling_parse_context_builder.h"
```
