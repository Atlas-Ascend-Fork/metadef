# SetPcieThroughFlag

<!-- md-trans-meta sourceCommit=7ba7d1f270370e0de2d9099271255419dd4c1b21 translatedAt=2026-10-09T03:46:05.487Z pushedAt=2026-10-15T03:48:04.968Z -->

## Function

Sets whether PCIE Through is supported.

## Function Prototype

```cpp
OpTilingContextBuilder &SetPcieThroughFlag(bool flag);
```

## Parameters

|Parameter|Input/Output| Description                                                             |
|--|--|----------------------------------------------------------------|
|flag|Input| Sets whether PCIE Through is supported (**true**: supported; **false**: not supported). |

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.
