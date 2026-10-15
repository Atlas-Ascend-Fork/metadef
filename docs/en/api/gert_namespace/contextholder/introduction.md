# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:39:55.703Z pushedAt=2026-10-15T03:48:04.849Z -->

**Context** is the context for executing the host-side implementation functions of the operator. Because the constructed **Context** stores only pointer types, the **ContextHolder** class is provided to facilitate lifecycle and ownership management of resources.

**Context** allows the host-side implementation functions of the operator to obtain the necessary input and output data through this context during execution. The host-side implementations of the operator include **Tiling**, **InferShape**, **InferShapeRange**, **InferDataType**, and **InferFormat**. Each implementation function has a corresponding **Context** type as its input parameter. For example, the input parameter of the **Tiling** implementation function is **TilingContext** and the input parameter of the **InferShape** implementation function is **InferShapeContext**.

To facilitate the construction of **Context** during operator host-side execution, we provide construction methods for various **Context** types, collectively referred to as the **OpxxxContextBuilder** classes, to shield the complexity of the underlying data structures and simplify the construction process. For example, for constructing **TilingContext**, we provide the **OpTilingContextBuilder** class.

The **OpxxxContextBuilder** series APIs are listed as follows:

- [OpInferDataTypeContextBuilder](../opinferdatatypecontextbuilder/OpInferDataTypeContextBuilder.md), used to construct [InferDataTypeContext](../inferdatatypecontext/InferDataTypeContext.md);
- [OpInferShapeContextBuilder](../opinfershapecontextbuilder/OpInferShapeContextBuilder.md), used to construct [InferShapeContext](../infershapecontext/InferShapeContext.md);
- [OpInferShapeRangeContextBuilder](../opinfershaperangecontextbuilder/OpInferShapeRangeContextBuilder.md), used to construct [InferShapeRangeContext](../infershaperangecontext/InferShapeRangeContext.md);
- [OpKernelContextBuilder](../opkernelcontextbuilder/OpKernelContextBuilder.md), used to construct [KernelContext](../internal_interface.md#kernelcontext-class);
- [OpTilingContextBuilder](../optilingcontextbuilder/OpTilingContextBuilder.md), used to construct [TilingContext](../tilingcontext/TilingContext.md);
- [OpTilingParseContextBuilder](../optilingparsecontextbuilder/OpTilingParseContextBuilder.md), used to construct [TilingParseContext](../internal_interface.md#tilingparsecontext-class).

**OpxxxContextBuilder** is used to create a **ContextHolder**, which is responsible for managing the memory resources pointed to by the pointers in the **Context**. The corresponding **Context** can be obtained through the **ContextHolder**.

## Header Files to Include

```cpp
#include "base/context_builder/context_holder.h"
```
