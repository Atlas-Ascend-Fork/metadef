# ge::graphStatus

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:11:00.143Z pushedAt=2026-10-15T03:48:04.673Z -->

The **graphStatus** type is the **uint32\_t** type, and its different statuses are described as follows:

|Status|Value|Description|
|--|--|--|
|ge::GRAPH_SUCCESS|0|The corresponding function is executed successfully.|
|ge::GRAPH_FAILED|0xFFFFFFFF|The corresponding function fails to execute.|
|ge::GRAPH_PARAM_INVALID|50331649|The corresponding function fails to execute because some parameters fail validation.|
|ge::GRAPH_NOT_CHANGED|1343242304|Error code returned when the conditions for constant folding are not met.|
|ge::GRAPH_NODE_WITHOUT_CONST_INPUT|50331648|Scenario where an operator in the network is detected to have an input without const data.|
|ge::GRAPH_NODE_NEED_REPASS|50331647|The graph node needs to be reprocessed or traversed, commonly in the infershape phase.|
|ge::GRAPH_INVALID_IR_DEF|50331646|Invalid IR definition.|
|ge::OP_WITHOUT_IR_DATATYPE_INFER_RULE|50331645|The operator lacks an IR data type inference rule.|
|ge::GRAPH_PARAM_OUT_OF_RANGE|50331644|The value of a function parameter exceeds the allowed valid range.|
|ge::GRAPH_MEM_OPERATE_FAILED|50331539|A memory operation (such as allocation or release) fails.|
|ge::GRAPH_NULL_PTR|50331538|An illegal null pointer is encountered inside the function.|
|ge::GRAPH_MEMCPY_FAILED|50331537|A memory copy operation fails.|
|ge::GRAPH_MEMSET_FAILED|50331536|A memory set operation fails.|
|ge::GRAPH_MATH_CAL_FAILED|50331429|A mathematical calculation (such as convolution or matrix multiplication) fails.|
|ge::GRAPH_ADD_OVERFLOW|50331428|The addition result overflows.|
|ge::GRAPH_MUL_OVERFLOW|50331427|The multiplication result overflows.|
|ge::GRAPH_RoundUp_Overflow|50331426|The round-up operation causes an overflow.|
