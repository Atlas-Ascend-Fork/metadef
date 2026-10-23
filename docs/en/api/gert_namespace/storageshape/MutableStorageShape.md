# MutableStorageShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:06:15.628Z pushedAt=2026-10-15T03:48:05.011Z -->

## Function

Obtains the writable runtime shape.

## Function Prototype

```cpp
Shape &MutableStorageShape()
```

## Parameters

None

## Return Value

Writable runtime shape.

## Constraints

None

## Example

```cpp
StorageShape shape({3, 256, 256}, {256, 256, 3});
auto storage_shape = shape.MutableStorageShape(); // 256,256,3
```
