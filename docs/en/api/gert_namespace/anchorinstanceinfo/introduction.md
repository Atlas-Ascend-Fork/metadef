# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:26:11.238Z pushedAt=2026-10-15T03:48:04.791Z -->

This class describes the mapping between the input/output information in the operator prototype definition and the actual inputs/outputs after operator instantiation. Each **AnchorInstanceInfo** object corresponds to one input or output and records two key pieces of information:

- **instantiation\_num\_**: Number of instances that the input or output in the prototype definition corresponds to among the actual inputs or outputs.
- **instance\_start\_**: Starting index of the input or output in the prototype definition among the actual inputs or outputs.

The current prototype definition provides three types of inputs: required input, optional input, and dynamic input; it provides only one type of output: required output. The details are as follows:

|Input Type|instantiation_num_|instance_start_|
|--|--|--|
|Required input|Must be **1**; otherwise, an error is reported.|The value of **instance_start_** starts from 0. For example, if the i-th instance is denoted as A and the (i - 1)-th instance is denoted as B, the following derivation holds: A.instance_start_ = B.instance_start_ + B.instantiation_num_.|
|Optional input|**1** when there is an actual input; otherwise, **0**.|The value of **instance_start_** starts from 0. For example, if the i-th instance is denoted as A and the (i - 1)-th instance is denoted as B, the following derivation holds: A.instance_start_ = B.instance_start_ + B.instantiation_num_.|
|Dynamic input|1 to N, depending on the number of actual inputs.|The value of **instance_start_** starts from 0. For example, if the i-th instance is denoted as A and the (i - 1)-th instance is denoted as B, the following derivation holds: A.instance_start_ = B.instance_start_ + B.instantiation_num_.|
|Required output|Must be **1**; otherwise, an error is reported.|The value of **instance_start_** starts from 0. For example, if the i-th instance is denoted as A and the (i - 1)-th instance is denoted as B, the following derivation holds: A.instance_start_ = B.instance_start_ + B.instantiation_num_.|

## Header Files to Include

```cpp
#include <compute_node_info.h>
```
