# AttrDataType

AttrDataType枚举值定义如下：

```cpp
enum class AttrDataType : int32_t {
  kBool = 0,             ///< bool类型
  kString,               ///< 字符串类型
  kInt32,                ///< int32类型
  kInt64,                ///< int64类型
  kUint32,               ///< uint32类型
  kFloat32,              ///< float32类型
  kFloat16,              ///< float16类型
  kListBool,             ///< bool列表类型
  kListString,           ///< 字符串列表类型
  kListInt32,            ///< int32列表类型
  kListInt64,            ///< int64列表类型
  kListUint32,           ///< uint32列表类型
  kListFloat32,          ///< float32列表类型
  kListFloat16,          ///< float16列表类型
  kListListInt32,        ///< int32二维列表类型
  kListListInt64,        ///< int64二维列表类型
  kBfloat16,             ///< bfloat16类型
  kInt8,                 ///< int8类型
  kInt16,                ///< int16类型
  kListInt8,             ///< int8列表类型
  kListInt16,            ///< int16列表类型
  kListListBool,         ///< bool二维列表类型
  kListListFloat16,      ///< float16二维列表类型
  kListBfloat16,         ///< bfloat16列表类型
  kListListBfloat16,     ///< bfloat16二维列表类型
  kListListFloat32,      ///< float32二维列表类型
  kListListInt8,         ///< int8二维列表类型
  kListListInt16,        ///< int16二维列表类型
  kUint8,                ///< uint8类型
  kListUint8,            ///< uint8列表类型
  kListListUint8,        ///< uint8二维列表类型
  kUint16,               ///< uint16类型
  kListUint16,           ///< uint16列表类型
  kListListUint16,       ///< uint16二维列表类型
  kListListUint32,       ///< uint32二维列表类型
  kUint64,               ///< uint64类型
  kListUint64,           ///< uint64列表类型
  kListListUint64,       ///< uint64二维列表类型
  kTypeEnd               ///< 数据类型边界标记
};
```
