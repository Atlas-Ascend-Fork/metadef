# AttrDataType

The enumeration values of **AttrDataType** are defined as follows:

```cpp
enum class AttrDataType : int32_t {
  kBool = 0,             ///< bool type
  kString,               ///< string type
  kInt32,                ///< int32 type
  kInt64,                ///< int64 type
  kUint32,               ///< uint32 type
  kFloat32,              ///< float32 type
  kFloat16,              ///< float16 type
  kListBool,             ///< list of bool
  kListString,           ///< list of string
  kListInt32,            ///< list of int32
  kListInt64,            ///< list of int64
  kListUint32,           ///< list of uint32
  kListFloat32,          ///< list of float32
  kListFloat16,          ///< list of float16
  kListListInt32,        ///< two-dimensional list of int32
  kListListInt64,        ///< two-dimensional list of int64
  kBfloat16,             ///< bfloat16 type
  kInt8,                 ///< int8 type
  kInt16,                ///< int16 type
  kListInt8,             ///< list of int8
  kListInt16,            ///< list of int16
  kListListBool,         ///< two-dimensional list of bool
  kListListFloat16,      ///< two-dimensional list of float16
  kListBfloat16,         ///< list of bfloat16
  kListListBfloat16,     ///< two-dimensional list of bfloat16
  kListListFloat32,      ///< two-dimensional list of float32
  kListListInt8,         ///< two-dimensional list of int8
  kListListInt16,        ///< two-dimensional list of int16
  kUint8,                ///< uint8 type
  kListUint8,            ///< list of uint8
  kListListUint8,        ///< two-dimensional list of uint8
  kUint16,               ///< uint16 type
  kListUint16,           ///< list of uint16
  kListListUint16,       ///< two-dimensional list of uint16
  kListListUint32,       ///< two-dimensional list of uint32
  kUint64,               ///< uint64 type
  kListUint64,           ///< list of uint64
  kListListUint64,       ///< two-dimensional list of uint64
  kTypeEnd               ///< Boundary marker of data types
};
```
