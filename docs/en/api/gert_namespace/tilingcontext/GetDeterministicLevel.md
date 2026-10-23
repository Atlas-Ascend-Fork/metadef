# GetDeterministicLevel

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:34:59.332Z pushedAt=2026-10-15T03:48:05.075Z -->

## Function

Obtains the deterministic computation level configuration option. For the setting API, see [DeterministicLevel](../optilingcontextbuilder/DeterministicLevel.md).

## Function Prototype

```cpp
int32_t GetDeterministicLevel() const
```

## Parameters

None

## Return Value

**0**: The deterministic configuration option is not enabled.

**1**: The deterministic configuration option is enabled.

**2**: The strong consistency configuration option is enabled.

**3**: The batch consistency configuration option is enabled.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  int32_t ret = context->GetDeterministicLevel();
  // ...
}
```
