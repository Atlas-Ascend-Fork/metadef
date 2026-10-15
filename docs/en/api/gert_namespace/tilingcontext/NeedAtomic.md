# NeedAtomic

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:48:39.155Z pushedAt=2026-10-15T03:48:05.098Z -->

## Function

Obtains the flag value indicating whether atomic clean is required.

## Function Prototype

```cpp
bool NeedAtomic() const
```

## Parameters

None

## Return Value

- **true**: Atomic clean is required.
- **false**: Atomic clean is not required.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  bool is_need_atomic = context->NeedAtomic();
  // ...
}
```
