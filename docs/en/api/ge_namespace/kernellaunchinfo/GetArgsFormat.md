# GetArgsFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:27:52.794Z pushedAt=2026-10-15T03:48:04.701Z -->

## Function

Gets the **ArgsFormat** of the operator.

## Function Prototype

```cpp
const char *GetArgsFormat() const
```

## Parameters

None

## Return Value

Returns the **ArgsFormat** of the operator on success.

Returns **nullptr** on failure.

## Constraints

Only tasks of the **AI CPU** and **AI Core** types can obtain the **ArgsFormat**.

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  auto aicore_args_format_str = aicore_task.GetArgsFormat();
  auto aicore_args_format = ArgsFormatSerializer::Deserialize(aicore_args_format_str);
  ...
}
```
