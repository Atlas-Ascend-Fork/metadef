# GetInstanceStart

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:25:07.975Z pushedAt=2026-10-15T03:48:04.790Z -->

## Function

Obtains the index of the first instantiated instance of the current input/output **Anchor**.

## Function Prototype

```cpp
size_t GetInstanceStart() const
```

## Parameters

None

## Return Value

Index of the first instantiated instance.

## Constraints

None

## Example

```cpp
AnchorInstanceInfo anchor_0(0, 10); //The first input defined in the IR prototype is a dynamic input, and the actual number of inputs of the dynamic input is 10.
AnchorInstanceInfo anchor_1(10, 1); //The second input defined in the IR prototype is a required input, whose actual number of inputs must be 1, and this input is the 10th actual input.
auto start_of_anchor_1 = anchor_1.GetInstanceStart(); // start_of_anchor_1 = 10
```
