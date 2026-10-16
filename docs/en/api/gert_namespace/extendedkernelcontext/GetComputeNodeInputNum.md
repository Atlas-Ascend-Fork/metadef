# GetComputeNodeInputNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:55:27.049Z pushedAt=2026-10-15T03:48:04.882Z -->

## Function

Obtains the number of inputs of the operator.

## Function Prototype

```cpp
size_t GetComputeNodeInputNum() const
```

## Parameters

None

## Return Value

Number of inputs of the operator.

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeInputNum(); ++idx) {
  auto input_td = extend_context->GetInputDesc(idx);
  ...
}
```
