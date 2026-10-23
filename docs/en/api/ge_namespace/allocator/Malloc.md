# Malloc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:20:41.995Z pushedAt=2026-10-15T03:48:04.688Z -->

## Function

Allocates device memory of the specified size in the user memory pool.

## Function Prototype

```cpp
virtual MemBlock *Malloc(size_t size) = 0
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|size|Input|Specifies the size of the memory to be allocated.|

## Return Value

Returns a [MemBlock](../memblock/MemBlock.md) pointer.

## Exception Handling

None

## Constraints

The pure virtual function must be implemented by the user.
