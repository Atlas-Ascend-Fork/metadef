# MallocAdvise

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:21:05.194Z pushedAt=2026-10-15T03:48:04.689Z -->

## Function

Allocates device memory of the specified **size** in the user memory pool, with the suggested memory address being **addr**.

## Function Prototype

```cpp
virtual MemBlock *MallocAdvise(size_t size, void *addr)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|size|Input|Specifies the memory size to be allocated.|
|addr|Input|Suggested memory address to be allocated.|

## Return Value

Returns a [MemBlock](../memblock/MemBlock.md) pointer.

## Exception Handling

None

## Constraints

The virtual function must be implemented by the user. If it is not implemented, it behaves the same as [Malloc](Malloc.md) by default.
