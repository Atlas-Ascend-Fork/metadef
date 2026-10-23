# MemBlock Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:34:56.842Z pushedAt=2026-10-15T03:48:04.712Z -->

## Function

**MemBlock** constructor and destructor.

## Function Prototype

```cpp
MemBlock(Allocator &allocator, void *addr, size_t block_size)
: allocator_(allocator), addr_(addr), count_(1U), block_size_(block_size) {}
virtual ~MemBlock() = default
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|allocator|Input|Reference to a class derived from **Allocator**.|
|addr|Input|Device memory address.|
|block_size|Input|Size of the device memory **addr**.|

## Return Value

The **MemBlock** constructor returns a **MemBlock** object.

## Exception Handling

None

## Constraints

After inheriting [Allocator](../allocator/Allocator.md), users need to return a **MemBlock** type pointer when allocating memory. Users only need to construct a **MemBlock** object using the constructor. The destructor can be customized according to user requirements to avoid memory leaks.
