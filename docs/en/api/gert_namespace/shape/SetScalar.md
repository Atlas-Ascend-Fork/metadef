# SetScalar

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:00:25.277Z pushedAt=2026-10-15T03:48:04.998Z -->

## Function

Sets shape as a scalar.

## Function Prototype

```cpp
void SetScalar()
```

## Parameters

None

## Return Value

None

## Constraints

None

## Example

```cpp
Shape shape0({3, 256, 256});
shape0.IsScalar(); // false
shape0.SetScalar();
shape0.IsScalar(); // true
```
