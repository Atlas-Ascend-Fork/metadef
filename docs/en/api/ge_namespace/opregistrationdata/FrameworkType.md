# FrameworkType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:40:27.499Z pushedAt=2026-10-15T03:48:04.722Z -->

## Function

Sets the framework type of the original model.

## Function Prototype

```cpp
OpRegistrationData &FrameworkType(const domi::FrameworkType &fmk_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|fmk_type|Input|The enumeration values are defined as follows: **enum FrameworkType {CAFFE = 0,MINDSPORE = 1,TENSORFLOW = 3,ANDROID_NN,ONNX,FRAMEWORK_RESERVED,};**|
