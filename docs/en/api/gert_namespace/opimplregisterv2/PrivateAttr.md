# PrivateAttr

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:32:59.741Z pushedAt=2026-10-15T03:48:04.943Z -->

## Function

Registers the private attribute of an operator.

An operator attribute consists of an attribute name and an attribute value.

Normally, when registering a private attribute of an operator, the user needs to specify both the name **private\_attr** and the value **private\_attr\_val** of the private attribute. This is referred to as scenario 1. However, considering that an operator may already have a certain attribute, the user is also allowed to set only the attribute name when setting that attribute, which is referred to as scenario 2. Therefore, two types of registration functions are provided, corresponding to the two scenarios above.

For scenario 1, if the operator already has a certain attribute and the user resets its attribute value, the existing attribute value of the operator will be overwritten by the attribute registered by the user.

For scenario 2, if the operator does not have a certain attribute and the user sets only the attribute name, an error that the attribute cannot be found will occur later when obtaining the operator's private attribute list.

## Function Prototype

- API for setting only the private attribute name

  ```cpp
  OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr)
  ```

- API for setting both the attribute name and the attribute value

  ```cpp
  OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, int64_t private_attr_val)
  OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, const std::vector<int64_t> &private_attr_val)
  OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, const ge::char_t *private_attr_val)
  OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, ge::float32_t private_attr_val)
  OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, bool private_attr_val)
  OpImplRegisterV2 &PrivateAttr(const ge::char_t *private_attr, const std::vector<ge::float32_t> &private_attr_val)
  ```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|private_attr|Input|Name of the private attribute to be registered.|
|private_attr_val|Input|Attribute value corresponding to the name of the private attribute to be registered.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the private attribute.

## Constraints

None
