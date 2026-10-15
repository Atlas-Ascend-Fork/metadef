# GetPcieThroughFlag

<!-- md-trans-meta sourceCommit=7ba7d1f270370e0de2d9099271255419dd4c1b21 translatedAt=2026-10-09T04:42:09.795Z pushedAt=2026-10-15T03:48:05.086Z -->

## Function

Checks whether PCIE Through is enabled in the current context.

## Function Prototype

```cpp
bool GetPcieThroughFlag() const
```

## Parameters

None

## Return Value

**true**: The current context has enabled PCIE Through.

**false**: The current context has not enabled PCIE Through.

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  bool ret = context->GetPcieThroughFlag();
  // ...
}
```
