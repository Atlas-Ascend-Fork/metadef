# GetStorageShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:05:06.225Z pushedAt=2026-10-15T03:48:05.009Z -->

## Function

Obtains the runtime shape.

## Function Prototype

```cpp
const Shape &GetStorageShape() const
```

## Parameters

None

## Return Value

Runtime shape.

## Constraints

None

## Example

```cpp
StorageShape shape({3, 256, 256}, {256, 256, 3});
auto storage_shape = shape.GetStorageShape(); // 256,256,3
```
