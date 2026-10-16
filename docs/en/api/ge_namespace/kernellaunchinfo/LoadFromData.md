# LoadFromData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:31:24.571Z pushedAt=2026-10-15T03:48:04.706Z -->

## Function

Provides the capability to deserialize a serialized task. It is mainly used in the **GenerateTask** function to deserialize the task constructed by the framework and then modify its parameters.

## Function Prototype

```cpp
static KernelLaunchInfo LoadFromData(const gert::ExeResGenerationContext *context, const std::vector<uint8_t> &data)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|context|Input|Input parameter of the **GenerateTask** function, which stores the basic information of the operator.|
|data|Input|Result of serializing **KernelLaunchInfo**.|

## Return Value

Returns the deserialized result of the **data** input parameter.

## Constraints

None

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
   ....
  // Change the ArgsFormat of the original AI Core task.
  auto aicore_task = KernelLaunchInfo::LoadFromData(context, tasks.back());
  // Obtain argsformat from the task.
  auto aicore_args_format_str = aicore_task.GetArgsFormat();
  auto aicore_args_format = ArgsFormatSerializer::Deserialize(aicore_args_format_str);
  size_t i = 0UL;
  // Find the position of the first input address.
  for (; i < aicore_args_format.size(); i++) {
    if (aicore_args_format[i].GetType() == ArgDescType::kIrInput ||
        aicore_args_format[i].GetType() == ArgDescType::kInputInstance) {
      break;
    }
  }
  // Insert a communication address before the input address.
  aicore_args_format.insert(aicore_args_format.begin() + i, ArgDescInfo::CreateHiddenInput(HiddenInputSubType::kHcom));
  // Serialize the modified argsformat and set it back to the task.
  aicore_task.SetArgsFormat(ArgsFormatSerializer::Serialize(aicore_args_format).GetString());
  // Re-serialize and set it to the tasks.
  tasks.back() = aicore_task.Serialize();
  return SUCCESS;
}
```
