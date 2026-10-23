# GetShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:05:05.891Z pushedAt=2026-10-15T03:48:05.008Z -->

## Function

Obtains the original shape.

## Function Prototype

```cpp
const Shape &GetShape() const
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
auto origin_shape = shape.GetShape(); // 3,256,256
```
