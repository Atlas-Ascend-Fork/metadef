# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:04:41.956Z pushedAt=2026-10-15T03:48:05.008Z -->

## Function

Constructs a runtime shape instance.

## Function Prototype

```cpp
StorageShape()
StorageShape(const std::initializer_list<int64_t> &origin_shape, const std::initializer_list<int64_t> &storage_shape)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**origin_shape**|Input|Original shape.|
|**storage_shape**|Input|Runtime shape.|

## Return Value

Returns an initialized **StorageShape** object.

## Constraints

None

## Example

```cpp
StorageShape shape({3, 256, 256}, {3, 256, 256});
```
