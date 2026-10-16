# IsValid

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:55:48.580Z pushedAt=2026-10-15T03:48:04.749Z -->

## Function

Checks whether a tensor object is valid.

The tensor object is valid if the size of the actual tensor data is consistent with the tensor data size described by **TensorDesc**.

## Function Prototype

```cpp
graphStatus IsValid()
```

## Parameters

None

## Return Value

**graphStatus** type: If the tensor object is valid, returns **GRAPH\_SUCCESS**; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

None
