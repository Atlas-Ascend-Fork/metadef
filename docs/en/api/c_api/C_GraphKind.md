# C\_GraphKind

C\_GraphKind indicates the backend category of a graph, which is used to distinguish a compute graph from an execute graph. The graph category is determined when the graph is constructed and cannot be switched afterwards. On the C++ side, this enum is used through the ge::GraphKind alias.

The C\_GraphKind enum values are defined as follows:

```c
typedef enum {
  C_GRAPH_COMPUTE = 0,  // compute graph
  C_GRAPH_EXECUTE = 1,  // execute graph
} C_GraphKind;
```

- C\_GRAPH\_COMPUTE: compute graph.
- C\_GRAPH\_EXECUTE: execute graph.

The enum values (0/1) are an external contract and remain unchanged. Downstream components must keep consistent when interfacing by value.
