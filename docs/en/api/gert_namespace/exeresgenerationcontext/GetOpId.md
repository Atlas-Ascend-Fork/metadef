# GetOpId

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:47:40.129Z pushedAt=2026-10-15T03:48:04.865Z -->

## Function

Obtains the unique ID of the current operator.

## Function Prototype

```cpp
int64_t GetOpId() const
```

## Parameters

None

## Return Value

Returns an integer of the **int64\_t** type, representing the unique ID of this operator in the computation graph.

## Constraints

None

## Example

```cpp
int64_t GetOpId(ExeResGenerationContext* context) {
  auto opId= context->GetOpId();
  // ...
}
```
