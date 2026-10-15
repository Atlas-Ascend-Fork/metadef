# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:36:46.908Z pushedAt=2026-10-15T03:48:04.842Z -->

**ComputeNodeInfo** is used to serialize and store the compilation information of an operator, including the operator type, operator name, number of inputs and outputs, basic information of compile-time tensors (**CompileTimeTensorDesc**), and input/output instantiation information (**AnchorInstanceInfo**). In addition, this class supports getting and setting the values of attributes defined in the operator prototype (**RuntimeAttrs**). The serialized memory space of **ComputeNodeInfo** is flat, and the memory layout order is: **ComputeNodeInfo** data members, operator input/output instantiation information, basic information of compile-time tensors (the number of which equals the actual number of inputs and outputs), and operator attribute information.

## Header Files to Include

```cpp
#include <compute_node_info.h>
```
