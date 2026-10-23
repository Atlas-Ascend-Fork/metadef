# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:22:26.071Z pushedAt=2026-10-15T03:48:04.923Z -->

**OpCheckContext** inherits from **ExtendedKernelContext** and is a context class used for operator parameter and shape validation. The core purpose of **OpCheckContext** is to validate the shapes, data types, and dimensions of input and output tensors before operator registration or execution, ensuring that the operator runs safely and correctly.

The inheritance relationship of **OpCheckContext** is as follows:

![](../../figures/opcheck_context.png)

## Header File to Include

```cpp
#include "exe_graph/runtime/exe_res_generation_context.h"
```
