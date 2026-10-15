# GetScheduleMode

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:44:32.148Z pushedAt=2026-10-15T03:48:05.091Z -->

## Function

Obtains the schedule mode used when the operator is executed on the NPU.

## Function Prototype

```cpp
uint32_t GetScheduleMode() const
```

## Parameters

None

## Return Value

Returns **schedule\_mode**.

- **0**: normal mode, which is the default mode.
- **1**: batch mode, which needs to be set only in model execution scenarios where the model contains inter-core synchronization operators. This mode does not support scenarios where operators are called directly or indirectly through single-operator APIs.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForAdd(TilingContext *context) {
  auto schedule_mode = context->GetScheduleMode();
  ...
}
```
