# Promote

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:18:45.114Z pushedAt=2026-10-15T03:48:04.686Z -->

## Function

Represents the promoted type among the data types specified by inputs or attributes as the output data type.

## Function Prototype

```cpp
class Promote {
 public:
  Promote(const std::initializer_list<const char *> &syms);
  std::vector<const char *> Syms() const; // Return the symbol names involved in type promotion.
  Promote(const Promote &other) = delete;
  Promote &operator=(const Promote &other) = delete;
  Promote(Promote &&other) noexcept;
  Promote &operator=(Promote &&other) noexcept;
 private:
  std::shared_ptr<void> data_;
};
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|syms|Input|List of type symbols involved in the promotion, including symbols of input types or symbols specified by attributes.|
|other|Input|Another **Promote** object.|

## Return Value

None

## Exception Handling

None

## Constraints

None
