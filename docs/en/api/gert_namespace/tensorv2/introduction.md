# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:28:55.879Z pushedAt=2026-10-15T03:48:05.062Z -->

**TensorV2** is a tensor management class used to store and operate on tensor data. It records the shape, stride, offset, data format, data type, and storage location of a tensor, and provides APIs such as data address access and data size calculation. Compared with the tensor class, **TensorV2** additionally carries stride and offset information.

> [!NOTE] Note
> This is a reserved API kept for future functionality and is not supported in the current version.

## Header File to Include

```cpp
#include <tensor.h>
```
