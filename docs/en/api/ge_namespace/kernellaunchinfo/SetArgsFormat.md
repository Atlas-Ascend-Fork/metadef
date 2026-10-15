# SetArgsFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:31:44.448Z pushedAt=2026-10-15T03:48:04.707Z -->

## Function

Sets the **ArgsFormat** of the operator.

## Function Prototype

```cpp
graphStatus SetArgsFormat(const char *args_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**args_format**|Input|**ArgsFormat** of the operator.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../ge-graphStatus.md).

## Constraints

Only AI CPU and AI Core tasks require setting **ArgsFormat**.

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  auto aicore_args_format_str = aicore_task.GetArgsFormat();
  auto aicore_args_format = ArgsFormatSerializer::Deserialize(aicore_args_format_str);
  size_t i = 0UL;
  for (; i < aicore_args_format.size(); i++) {
    if (aicore_args_format[i].GetType() == ArgDescType::kIrInput ||
        aicore_args_format[i].GetType() == ArgDescType::kInputInstance) {
      break;
    }
  }
  // Insert HiddenInput.
  aicore_args_format.insert(aicore_args_format.begin() + i, ArgDescInfo::CreateHiddenInput(HiddenInputSubType::kHcom));
  aicore_task.SetArgsFormat(ArgsFormatSerializer::Serialize(aicore_args_format).GetString());
  ...
}
```
