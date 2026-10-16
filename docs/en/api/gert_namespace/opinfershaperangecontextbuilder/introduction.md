# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:39:37.504Z pushedAt=2026-10-15T03:48:04.954Z -->

**OpInferShapeRangeContextBuilder** is used to build **InferShapeRangeContext**. The constructed context serves as input during operator **ShapeRange** inference to obtain the necessary operator input and output data. After inference is complete, the results are written back to the context.

The inheritance relationship of **OpInferShapeRangeContextBuilder** is as follows:

![](../../figures/opinfershape_context_builder.png)

The usage steps are as follows:

1. Construct a **ContextHolder**.

   Call the **OpInferShapeRangeContextBuilder** API, pass in the corresponding input and output data, such as the input tensor shape range `gert::Range<gert::Tensor>` and the output **TensorDesc** description, and finally call the **Build\(\)** API to construct a `ContextHolder<InferShapeRangeContext>` object.

2. Obtain **InferShapeRangeContext**.

   Call the **GetContext** API through the **ContextHolder** to obtain **InferShapeRangeContext**.

3. Call the operator **ShapeRange** inference function **InferShapeRangeKernelFunc**, passing **InferShapeRangeContext** as the function input, to complete **ShapeRange** inference and write the inferred output results.
4. Obtain the inferred output shape range through the **GetOutputShapeRange** API of **InferShapeRangeContext**.
5. Release **ContextHolder** as needed. After the release is complete, all data pointers in the **InferShapeRangeContext** constructed by **Build** become invalid.

> [!NOTE] Note
> This class inherits from the **OpContextBuilderBase** class. Before **Build** constructs the **ContextHolder** object, call the **OpType**, **OpName**, **IONum** or **IOInstanceNum**, and **AppendAttr** APIs of **OpContextBuilderBase** to set the operator type, name, number of inputs and outputs, and operator attributes, respectively.

## Header File to Include

```cpp
#include "base/context_builder/op_infer_shape_range_context_builder.h"
```
