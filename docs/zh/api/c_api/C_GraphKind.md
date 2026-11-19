# C\_GraphKind

C\_GraphKind表示图的后端类别，用于区分计算图与执行图。图类别在构图时确定，构造后不可切换；C++侧通过ge::GraphKind别名使用该枚举。

C\_GraphKind枚举值定义如下：

```c
typedef enum {
  C_GRAPH_COMPUTE = 0,  // compute graph
  C_GRAPH_EXECUTE = 1,  // execute graph
} C_GraphKind;
```

- C\_GRAPH\_COMPUTE：计算图。
- C\_GRAPH\_EXECUTE：执行图。

枚举取值（0/1）为对外契约，固定不变，下游按数值对接时需保持一致。
