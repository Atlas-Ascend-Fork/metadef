# Allocator Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:19:50.017Z pushedAt=2026-10-15T03:48:04.687Z -->

## Function

Allocator constructor and destructor.

## Function Prototype

```cpp
Allocator() = default
virtual ~Allocator() = default
Allocator(const Allocator &) = delete
Allocator &operator=(const Allocator &) = delete
```

## Parameters

None

## Return Value

None

## Exception Handling

None

## Constraints

The pure virtual class must be derived by the user.
