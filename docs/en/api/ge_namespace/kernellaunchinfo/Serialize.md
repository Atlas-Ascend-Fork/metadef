# Serialize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:31:22.618Z pushedAt=2026-10-15T03:48:04.706Z -->

## Function

Serializes **KernelLaunchInfo** into a data stream.

## Function Prototype

```cpp
std::vector<uint8_t> Serialize()
```

## Parameters

None

## Return Value

Returns the serialized data stream.

## Constraints

None

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  // Create the WaitTask.
  auto wait_task = KernelLaunchInfo::CreateHcomWaitTask(context);
  wait_task.SetStreamId(attach_stream_id);
  // Serialize.
  tasks.insert(tasks.begin() + aicore_index, wait_task.Serialize());
  aicore_index++;
  ...
}
```
