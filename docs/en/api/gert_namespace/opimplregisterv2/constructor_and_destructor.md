# Constructors and Destructors

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:25:48.576Z pushedAt=2026-10-15T03:48:04.931Z -->

## Function

As a registration API class, **OpImplRegisterV2** provides a series of operator prototype registration APIs for users to register information such as the Tiling function, InferShape function, and private attributes of a specified operator type.

## Function Prototype

- Specifies the operator type as **op\_type**, constructs an **OpImplRegisterV2** object for operator registration, and performs default initialization on its registration data.

    ```cpp
    explicit OpImplRegisterV2(const ge::char_t *op_type)
    ```

- Move constructor and copy constructor. Both can register the **OpImplFunctions** data of another **OpImplRegisterV2** object **register\_data** into the map managed by the **OpImplRegistry** singleton, and generate a new default-initialized **OpImplRegisterV2** object.

    ```cpp
    OpImplRegisterV2(OpImplRegisterV2 &&register_data) noexcept
    OpImplRegisterV2(const OpImplRegisterV2 &register_data)
    OpImplRegisterV2 &operator=(const OpImplRegisterV2 &) = delete
    OpImplRegisterV2 &operator=(OpImplRegisterV2 &&) = delete
    ```

- Destructor

    ```cpp
    ~OpImplRegisterV2()
    ```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_type|Input|Specified operator type.|
|register_data|Input|Another registration object, which is a reference of type **OpImplRegisterV2**.|

## Return Value

An **OpImplRegisterV2** object used for operator registration.

## Constraints

None
