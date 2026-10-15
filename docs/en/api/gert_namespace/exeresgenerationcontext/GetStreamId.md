# GetStreamId

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:48:18.307Z pushedAt=2026-10-15T03:48:04.867Z -->

## Function

Returns the **StreamId** bound to the current operator.

## Function Prototype

```cpp
int64_t GetStreamId() const
```

## Parameters

None

## Return Value

Returns the **StreamId** bound to the current operator.

## Constraints

This API can be used only when each operator is bound to a single stream.

## Example

```cpp
int64_t GetStreamId(ExeResGenerationContext* context) {
  auto streamId= context->GetStreamId();
  ...
}
```
