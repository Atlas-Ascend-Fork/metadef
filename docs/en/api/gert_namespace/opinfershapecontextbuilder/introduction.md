# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:37:48.602Z pushedAt=2026-10-15T03:48:04.951Z -->

**OpInferShapeContextBuilder** is used to build **InferShapeContext**. The constructed context is passed as an input parameter during operator shape inference to obtain the necessary operator input and output data. After inference is complete, the results are written back to the context.

The inheritance relationship of **OpInferShapeContextBuilder** is as follows:

![](../../figures/opinfershape_context_builder.png)

The usage steps are as follows:

1. Construct a **ContextHolder**.

   Call the **OpInferShapeContextBuilder** API, pass in information such as the **Tensor** of the operator input and the **TensorDesc** description of the output, and finally call the **Build\(\)** API to construct a **ContextHolder<InferShapeContext\>** object.

2. Obtain **InferShapeContext**

   Call the **GetContext** API through **ContextHolder** to obtain **InferShapeContext**.

3. Call the operator shape inference function **InferShapeKernelFunc**, passing **InferShapeContext** as the function input parameter to complete shape inference and write the inferred output results.
4. Obtain the inferred output shape through the **GetOutputShape** API of **InferShapeContext**.
5. Release **ContextHolder** as needed. After the release is complete, all data pointers in the **InferShapeContext** constructed by **Build** become invalid.

> [!NOTE] Note
> This class inherits from the **OpContextBuilderBase** class. Before **Build** constructs the **ContextHolder** object, call the **OpType**, **OpName**, **IONum** or **IOInstanceNum**, and **AppendAttr** APIs of **OpContextBuilderBase** to set the operator type, name, number of inputs and outputs, and operator attributes, respectively.

## Header File to Include

```cpp
#include "base/context_builder/op_infer_shape_context_builder.h"
```
