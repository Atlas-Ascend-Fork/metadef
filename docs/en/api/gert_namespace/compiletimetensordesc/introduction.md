# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:30:13.517Z pushedAt=2026-10-15T03:48:04.827Z -->

**CompileTimeTensorDesc** describes the basic information of a compile-time tensor, including the data type (**ge::DataType**), the data layout format (**gert::StorageFormat**, including the original format and the runtime format), and the dimension expansion rules for converting the original format to the runtime format. This class provides methods for obtaining and setting the tensor data type, and supports management of the original format and the runtime format.

## Header Files to Include

```cpp
#include <compute_node_info.h>
```
