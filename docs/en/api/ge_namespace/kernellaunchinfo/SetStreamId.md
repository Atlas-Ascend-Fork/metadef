# SetStreamId

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:32:32.918Z pushedAt=2026-10-15T03:48:04.708Z -->

## Function

Sets the stream ID of the task.

## Function Prototype

```cpp
void SetStreamId(uint32_t stream_id)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|stream_id|Input|Stream ID.|

## Return Value

None

## Constraints

None

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto wait_task = KernelLaunchInfo::CreateHcomWaitTask(context);
  wait_task.SetStreamId(attach_stream_id);
  ...
}
```
