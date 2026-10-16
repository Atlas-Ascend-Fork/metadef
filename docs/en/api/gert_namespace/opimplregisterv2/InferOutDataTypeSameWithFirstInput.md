# InferOutDataTypeSameWithFirstInput

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:28:36.789Z pushedAt=2026-10-15T03:48:04.935Z -->

## Function

Registers a **datatype** inference rule that uses the **datatype** of the operator's first input as the **datatype** of all outputs.

## Function Prototype

```cpp
OpImplRegisterV2 &InferOutDataTypeSameWithFirstInput()
```

## Parameters

None

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **datatype** inference rule for the operator.

## Constraints

- After registering this rule, you do not need to register a custom inference rule. If both **InferDataType** and **InferOutDataTypeByFirstInput** are registered, the rule registered last is enabled.
- If the operator has no input or the **datatype** of the first input is undefined (**DT\_UNDEFINED**), an error is reported during inference.
