# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:48:14.784Z pushedAt=2026-10-15T03:48:05.097Z -->

**TilingContext** inherits from **ExtendedKernelContext** and is the context class used for operator tiling computation. It provides APIs for obtaining operator compilation information (**CompileInfo**), input/output shapes, input tensor values, and accessing operator tiling-related parameters. In operator tiling implementation, you can use this class to obtain the parameters on which tiling computation depends, and then save the tiling results (for example, **TilingKey** and **TilingData**) to the context for subsequent use during operator execution.

The inheritance diagram of **TilingContext** is as follows:

![](../../figures/tilingcontext.png)

## Header File to Include

```cpp
#include <tiling_context.h>
```
