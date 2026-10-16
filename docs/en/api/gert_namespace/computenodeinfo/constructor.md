# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:32:42.902Z pushedAt=2026-10-15T03:48:04.834Z -->

## Function

Constructor of the **ComputeNodeInfo** class.

## Function Prototype

```cpp
ComputeNodeInfo() = delete
ComputeNodeInfo(const ComputeNodeInfo &) = delete
ComputeNodeInfo(ComputeNodeInfo &&) = delete
ComputeNodeInfo &operator=(const ComputeNodeInfo &) = delete
ComputeNodeInfo &operator=(ComputeNodeInfo &&) = delete
```

## Parameters

None

## Return Value

None

## Constraints

POD type. Currently, explicit construction by calling the constructor is not allowed. It can be constructed by explicitly allocating memory.
