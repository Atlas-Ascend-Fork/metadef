# GetOriginShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:04:41.331Z pushedAt=2026-10-15T03:48:05.007Z -->

## Function

Obtains the original shape.

## Function Prototype

```cpp
const Shape &GetOriginShape() const
```

## Parameters

None

## Return Value

Original shape.

## Constraints

None

## Example

```cpp
StorageShape shape({3, 256, 256}, {256, 256, 3});
auto origin_shape = shape.GetOriginShape(); // 3,256,256
```
