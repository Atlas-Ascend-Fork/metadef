# Shape Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:01:26.067Z pushedAt=2026-10-15T03:48:04.999Z -->

## Function

Shape constructor.

## Function Prototype

In the following, **dim\_num\_** is the number of dimensions, that is, how many dimensions there are; **dims\_** is the specific dimension value information.

- Constructs a shape by default. In a shape instance constructed by default, the length of **dim\_num\_** is **0**.

  ```cpp
  Shape() : dim_num_(0), dims_{0}
  ```

- Constructs a shape from **dims\_ values**. For example, **Shape\(\{8,3,224,224\}\)** creates a shape instance with 4 dimensions, whose values are **8**, **3**, **224**, and **224** respectively.

  ```cpp
  Shape(const std::initializer_list<int64_t> &args) : Shape()
  ```

- Copy constructor. To improve performance, the space of **dims\_** beyond the source shape's **dim\_num\_** is not copied, and may contain dirty data.

  ```cpp
  Shape(const Shape &other)
  ```

- Copy assignment. To improve performance, the space of **dims\_** beyond the source shape's **dim\_num\_** is not copied, and may contain dirty data.

  ```cpp
  Shape &operator=(const Shape &other)
  ```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|args|Input|All **dim** values of the shape.|
|other|Input|Source shape object.|

## Return Value

Returns an initialized shape object.

## Constraints

None

## Example

```cpp
Shape shape({3, 256, 256}); // dim_num_=3  The first three dimensions of dims_ are 3, 256, 256.
```
