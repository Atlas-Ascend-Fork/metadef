# MutableOriginShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:05:48.821Z pushedAt=2026-10-15T03:48:05.010Z -->

## Function

Obtains the writable original shape.

## Function Prototype

```cpp
Shape &MutableOriginShape()
```

## Parameters

None

## Return Value

Writable original shape.

## Constraints

None

## Example

```cpp
StorageShape shape({3, 256, 256}, {256, 256, 3});
auto origin_shape = shape.MutableOriginShape(); // 3,256,256
```
