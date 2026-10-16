# Stride Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:09:50.160Z pushedAt=2026-10-15T03:48:05.020Z -->

## Function

**Stride** constructor.

## Function Prototype

In the following, dim\_num\_ is the number of dimensions, that is, how many dimensions there are; strides\_ is the specific stride information.

- Constructs a **Stride** object by default. In a default-constructed **Stride** object, the length of dim\_num\_ is 0.

    ```cpp
    Stride() : dim_num_(0), strides_{0}
    ```

- Constructs a **Stride** object from strides\_ values. For example, Stride\(\{18,9,3,1\}\) creates a **Stride** object with 4 dimensions, whose strides are 18, 9, 3, and 1 respectively.

    ```cpp
    Stride(const std::initializer_list<int64_t> &args) : Stride()
    ```

- Copy constructor. To improve performance, the space of strides\_ beyond that of the source **Stride** object dim\_num\_ is not copied, and may contain dirty data.

    ```cpp
    Stride(const Stride &other)
    ```

- Copy assignment. To improve performance, the space of **strides\_** beyond **dim\_num\_** of the source **Stride** object is not copied, and may contain dirty data.

    ```cpp
    Stride &operator=(const Stride &other)
    ```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|args|Input|All stride values of the **Stride** object.|
|other|Input|Source **Stride** object.|

## Return Value

Returns an initialized **Stride** object.

## Constraints

None

## Example

```cpp
Stride stride({3, 256, 256}); // dim_num_=3, strides_ describes the strides of the first three dimensions of the tensor as 3, 256, 256.
```
