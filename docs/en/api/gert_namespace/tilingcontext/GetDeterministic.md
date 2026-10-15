# GetDeterministic

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:34:38.135Z pushedAt=2026-10-15T03:48:05.075Z -->

## Function

Obtains the deterministic computation configuration options.

## Function Prototype

```cpp
int32_t GetDeterministic() const
```

## Parameters

None

## Return Value

**0**: The deterministic configuration option is disabled.

**1**: The deterministic configuration option is enabled.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  int32_t ret = context->GetDeterministic();
  // ...
}
```
