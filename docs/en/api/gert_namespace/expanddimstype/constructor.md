# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:51:25.220Z pushedAt=2026-10-15T03:48:04.875Z -->

## Function

Creates a dimension expansion rule.

## Function Prototype

- In the constructed instance, the dimension expansion rule (**mask\_**) and the dimension after expansion (size\_) are both 0.

    ```cpp
    ExpandDimsType() : size_(0U), mask_(0U)
    ```

- Create a dimension expansion rule from a string.

    ```cpp
    explicit ExpandDimsType(const ge::char_t *const expand_dims_type)
    ```

- Create a dimension expansion rule from the **int64\_t** bit field definition.

    ```cpp
    explicit ExpandDimsType(const int64_t reshape_type_mask)
    ```

## Parameters

**Table 1** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|expand_dims_type|Input|Dimension expansion rule described by a string. The maximum string length is 56 bytes.|
|reshape_type_mask|Input|Dimension expansion rule of the **int64_t** type, 64 bits in total. For the bit field definition in int, see the **int64_t** bit field definition. For simplicity, the dimension expansion rule part is in reverse order compared with the string. For example, if the dimension expansion rule described by the string is "1100", the corresponding dimension expansion rule is "0011", which is converted to the number 3. For the concept and description method of the dimension expansion rule, see the introduction.|

**Table 2** int64\_t bit field definition

|Field|Type|Description|
|--|--|--|
|High 8 bits|uint8_t|Length of the dimension expansion rule.|
|Low 56 bits|Bit field|Dimension expansion rule described using 0 and 1.|

## Return Value

Returns an **ExpandDimsType** object.

## Constraints

None

## Example

```cpp
ExpandDimsType type("1001"); // Set mask_ to 1001 and size_ to 4.
```
