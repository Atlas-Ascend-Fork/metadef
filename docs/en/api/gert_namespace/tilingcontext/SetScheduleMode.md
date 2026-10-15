# SetScheduleMode

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:52:23.941Z pushedAt=2026-10-15T03:48:05.105Z -->

## Function

Sets the schedule mode for executing an operator on the NPU.

## Function Prototype

```cpp
ge::graphStatus SetScheduleMode(const uint32_t schedule_mode)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**schedule_mode**|Input|**0**: normal mode. As long as there is an idle AI Core, the system schedules the operator's computation tasks to the idle core for computation. For example, an AI Core operator requires 4 cores. When an idle AI Core appears, the operator starts executing, and one of its computation slices is scheduled in advance to that idle core for computation, while the other computation slices wait for the remaining idle cores to appear before starting computation. The normal mode is used by default.<br>**1**: batch mode. The operator is scheduled for computation only after a sufficient number of AI Cores are idle. For example, an AI Core operator requires 4 AI Cores. The operator starts executing only when 4 cores are idle.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

Returns **ge::GRAPH\_FAILED** on failure.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

When using the multi-core synchronization feature, if the operator runs in a multi-stream scenario, you must enable batch mode through **SetScheduleMode\(1\)**; otherwise, a deadlock occurs and the process hangs.

In a multi-stream scenario, when the SyncAll operator of a stream is assigned to *n* physical cores while other streams preempt *m* of these cores (*m*<*n*), failing to enable batch mode causes the following: the *n*-*m* cores that start first wait for the remaining *m* cores to complete when reaching multi-core synchronization, while the remaining *m* cores have not started because their resources are preempted, resulting in a deadlock.

## Example

```cpp
ge::graphStatus TilingForAdd(TilingContext *context) {
  uint32_t batch_mode = 1U;
  auto ret = context->SetScheduleMode(batch_mode);
  GE_ASSERT_SUCCESS(ret);
  ...
}
```
