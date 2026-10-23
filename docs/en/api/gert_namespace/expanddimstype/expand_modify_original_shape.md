# Expand (Modifying the Original Shape)

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:51:24.206Z pushedAt=2026-10-15T03:48:04.875Z -->

## Function

Expands the dimensions of the shape and directly updates the original shape object with the expanded result.

## Function Prototype

```cpp
ge::graphStatus Expand(Shape &shape) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|shape|Input and output|Shape object on which the dimension expansion is performed.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on successful dimension expansion.

For the definition of the **ge::graphStatus** type, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
Shape shape({3, 256, 256}); // Set the original shape to 3,256,256.
ExpandDimsType type1("1000");
auto ret = type1.Expand(shape); // ret = ge::GRAPH_SUCCESS, shape = 1,3,256,256
```
