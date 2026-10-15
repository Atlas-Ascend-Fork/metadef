# GetSoName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:29:04.572Z pushedAt=2026-10-15T03:48:04.703Z -->

## Function

Obtains the so name of an AI CPU task.

## Function Prototype

```cpp
const char *GetSoName() const
```

## Parameters

None

## Return Value

Returns the so name of the operator on success.

Returns nullptr on failure.

## Constraints

Only AI CPU tasks can obtain the SO name.

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  // Obtain libcc_kernel.so.
  auto so_name = aicpu_task.GetSoName();
  ...
}
```
