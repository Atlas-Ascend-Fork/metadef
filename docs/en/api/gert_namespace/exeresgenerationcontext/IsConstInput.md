# IsConstInput

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:49:24.481Z pushedAt=2026-10-15T03:48:04.870Z -->

## Function

Determines whether an input tensor is constant data.

## Function Prototype

```cpp
bool IsConstInput(const ge::AscendString &name) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|name|Input|Name of the input tensor.|

## Return Value

**true** indicates that the input is a constant; **false** indicates that it is a dynamic input (such as input data and intermediate results).

## Constraints

None

## Example

```cpp
bool IsConstInput(ExeResGenerationContext *context) {
  ge::AscendString name = "XXX";
  bool status = *context->IsConstInput(name);
  ...
}
```
