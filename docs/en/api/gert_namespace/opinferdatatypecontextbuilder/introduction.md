# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:35:42.498Z pushedAt=2026-10-15T03:48:04.947Z -->

**OpInferDataTypeContextBuilder** is used to build **InferDataTypeContext**. The constructed context is used as an input parameter during operator data type inference to obtain the necessary operator input and output data. After the inference is complete, the result is written back to the context.

The inheritance relationship of **OpInferDataTypeContextBuilder** is as follows:

![](../../figures/opinfer_datatype_context_builder.png)

The usage procedure is as follows:

1. Construct a **ContextHolder**.

   Call the API of the **OpInferDataTypeContextBuilder** class, pass in information such as the input **TensorDesc** description, and call the **Build\(\)** API to construct a **ContextHolder<InferDataTypeContext\>** object.

2. Obtain the **InferDataTypeContext**.

   Obtain the **InferDataTypeContext** through the **GetContext** API of the **ContextHolder**.

3. Call the operator data type inference function **InferDataTypeKernelFunc**, pass the **InferDataTypeContext** as a function input parameter, complete the data type inference, and write the inferred output result.
4. Obtain the inferred output data type through the **GetOutputDataType** API of the **InferDataTypeContext**.
5. Release **ContextHolder** as needed. After the release, the data pointers in the **InferDataTypeContext** constructed by **Build** are all invalid.

> [!NOTE] Note
> This class inherits from the **OpContextBuilderBase** class. Before **Build** constructs the **ContextHolder** object, call the **OpType**, **OpName**, **IONum** or **IOInstanceNum**, and **AppendAttr** APIs of **OpContextBuilderBase** to set the operator type, name, number of inputs and outputs, and operator attributes, respectively.

## Header File to Include

```cpp
#include "base/context_builder/op_infer_datatype_context_builder.h"
```
