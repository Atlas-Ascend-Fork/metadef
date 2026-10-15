# GetInstanceNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:24:35.338Z pushedAt=2026-10-15T03:48:04.789Z -->

## Function

Obtains the number of instances of the current input/output **Anchor** (that is, the **instantiation\_num\_** field).

## Function Prototype

```cpp
size_t GetInstanceNum() const
```

## Parameters

None

## Return Value

Number of instances instantiated for this input/output **Anchor**.

## Constraints

None

## Example

```cpp
AnchorInstanceInfo anchor_0(0, 10); // The first input defined in the IR prototype is a dynamic input with 10 actual inputs.
auto input_num_0 = anchor_0.GetInstanceNum(); // input_num_0 = 10
```
