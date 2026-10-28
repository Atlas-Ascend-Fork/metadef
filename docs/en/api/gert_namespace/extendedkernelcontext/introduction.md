# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:01:35.022Z pushedAt=2026-10-15T03:48:04.891Z -->

**ExtendedKernelContext** is a subclass of **KernelContext**. On the basis of **KernelContext**, it encapsulates the context information processing APIs related to the compute node (that is, operator). It provides access APIs for the input, output, attributes, type, name, and other information of the compute node. The main purpose of this class is to simplify the acquisition and processing of compute node information. Users do not need to be aware of the layout of **KernelContext** information and can directly obtain it through the APIs of **ExtendedKernelContext**. As shown in the following figure, except for **KernelContext**, all subclasses at the remaining levels no longer contain any member variables. Therefore, all classes on this inheritance tree can be treated as POD classes and type-cast with the original **KernelContext**. In addition, the subclasses are merely wrapper classes and do not involve separate construction and destruction scenarios. Therefore, all constructors and destructors of the subclasses are disabled.

The inheritance relationship of **ExtendedKernelContext** is as follows:

![extended_kernel_context](../../figures/extended_kernel_context.png)

## Header File to Include

```cpp
#include <extended_kernel_context.h>
```
