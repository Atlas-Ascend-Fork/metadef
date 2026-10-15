# Expand (Outputting a New Shape)

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:51:52.590Z pushedAt=2026-10-15T03:48:04.877Z -->

## Function

Performs dimension expansion on a shape and writes the expanded result to the specified output shape object.

## Function Prototype

```cpp
ge::graphStatus Expand(const Shape &shape, Shape &out_shape) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|shape|Input|Input shape, which is the shape before dimension expansion.|
|out_shape|Output|Output shape, which is the shape after dimension expansion.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success; otherwise, returns **ge::GRAPH\_FAILED**.

For the definition of the **ge::graphStatus** type, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
Shape origin_shape({3, 256, 256}); // Set the original shape to 3x256x256.
Shape out_shape;
ExpandDimsType type1("1000");
ExpandDimsType type2("10000");
ExpandDimsType type3("1001");
auto ret = type1.Expand(origin_shape, out_shape); // ret = ge::GRAPH_SUCCESS, out_shape = 1,3,256,256
ret = type2.Expand(origin_shape, out_shape); // ret = ge::GRAPH_FAILED
ret = type3.Expand(origin_shape, out_shape); // ret = ge::GRAPH_SUCCESS, out_shape = 1,3,256,1,256
```
