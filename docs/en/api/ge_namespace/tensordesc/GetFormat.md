# GetFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:02:53.712Z pushedAt=2026-10-15T03:48:04.759Z -->

## Function

Obtains **Format** of the tensor described by **TensorDesc**.

## Function Prototype

```cpp
Format GetFormat() const
```

## Parameters

None

## Return Value

[Format](../Format.md) type: **Format** information of the tensor described by **TensorDesc**.

## Exception Handling

None

## Constraints

Because the returned **Format** information is a value copy, modifying the returned **Format** information does not affect the existing **Format** information in **TensorDesc**.
