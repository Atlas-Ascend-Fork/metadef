# GetKernelName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:28:53.829Z pushedAt=2026-10-15T03:48:04.702Z -->

## Function

Obtains the kernel entrypoint function name of an AI CPU task.

## Function Prototype

```cpp
const char *GetKernelName() const
```

## Parameters

None

## Return Value

Returns the kernel entrypoint function name of the operator on success.

Returns **nullptr** on failure.

## Constraints

The kernel entrypoint function name can be obtained only for AI CPU tasks.

## Example

```cpp
graphStatus Mc2GenTaskCallback(const gert::ExeResGenerationContext *context,
    std::vector<std::vector<uint8_t>> &tasks) {
  ...
  auto aicpu_task = KernelLaunchInfo::CreateAicpuKfcTask(context,
      "libccl_kernel.so", "RunAicpuKfcSrvLaunch");
  // Obtain RunAicpuKfcSrvLaunch.
  auto so_name = aicpu_task.GetKernelName();
  ...
}
```
