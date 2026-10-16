# GetExecuteMode

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:46:34.981Z pushedAt=2026-10-15T03:48:04.863Z -->

## Function

Returns the execution mode in which the current operator runs.

## Function Prototype

```cpp
ExecuteMode GetExecuteMode() const
```

## Parameters

None

## Return Value

Returns the **ExecuteMode** enumeration value, indicating the execution mode of the current operator.

```cpp
enum class ExecuteMode {
  kStaticOffloadExecute, // Executes in static graph mode.
  kDynamicExecute, // Executes in dynamic graph mode.
  kEnd  //end
};
```

## Constraints

None

## Example

```cpp
ExecuteMode  GetExecuteMode(ExeResGenerationContext *context) {
  ExecuteMode mode = *context->GetExecuteMode();
  ...
}
```
