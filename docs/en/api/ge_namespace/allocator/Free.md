# Free

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:20:26.696Z pushedAt=2026-10-15T03:48:04.687Z -->

## Function

Releases memory to the memory pool based on the specified **MemBlock**.

## Function Prototype

```cpp
virtual void Free(MemBlock *block) = 0
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|block|Input|Memory block pointer.|

## Return Value

None

## Exception Handling

None

## Constraints

The pure virtual function must be implemented by users.
