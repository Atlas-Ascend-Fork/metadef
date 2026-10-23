# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:49:17.820Z pushedAt=2026-10-15T03:48:04.869Z -->

**ExeResGenerationContext** is inherited from **ExtendedKernelContext** and is a context class for generating execution resources. It is mainly used to generate or configure various resources required for execution before an operator is executed, including memory, asynchronous execution streams, synchronization resources, operator attributes, and shape information of input and output tensors.

The inheritance relationship of **ExeResGenerationContext** is as follows:

![](../../figures/exe_res_generation_context.png)

## Header Files to Include

```cpp
#include "exe_graph/runtime/exe_res_generation_context.h"
```
