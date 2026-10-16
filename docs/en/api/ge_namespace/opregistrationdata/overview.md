# Overview

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:46:07.454Z pushedAt=2026-10-15T03:48:04.733Z -->

After developers complete the implementation code of a custom operator, they need to develop an adapter plugin to map the operator based on a third-party framework to an operator adapted to the AI processor. The **REGISTER\_CUSTOM\_OP** macro can be called to implement operator conversion. When calling the **REGISTER\_CUSTOM\_OP** macro, start with **REGISTER\_CUSTOM\_OP** and chain APIs such as **FrameworkType**, **OriginOpType**, and **ParseParamsFn** with ".".

For example:

```cpp
REGISTER_CUSTOM_OP("OpType")
   .FrameworkType(TENSORFLOW)
   .OriginOpType("OriginOpType")
   .ParseParamsByOperatorFn(ParseParamFunc)
   .ImplyType(ImplyType::TVM);
```
