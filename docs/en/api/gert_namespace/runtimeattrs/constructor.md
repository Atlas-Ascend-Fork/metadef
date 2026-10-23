# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:53:28.249Z pushedAt=2026-10-15T03:48:04.983Z -->

## Function

Constructor of the **RuntimeAttrs** class.

## Function Prototype

```cpp
RuntimeAttrs() = delete
RuntimeAttrs(const RuntimeAttrs &) = delete
RuntimeAttrs(RuntimeAttrs &&) = delete
RuntimeAttrs &operator=(const RuntimeAttrs &) = delete
RuntimeAttrs &operator=(RuntimeAttrs &&) = delete
```

## Parameters

None

## Return Value

None

## Constraints

POD type. Currently, explicit construction by calling the constructor is not allowed; it can be constructed by explicitly allocating memory.
