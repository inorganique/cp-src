# 边双连通分量

## 介绍

对于一个无向图, 如果删除任何一条边, 都不能使得 $u, v$ 两个点不连通, 则 $u, v$ 属于同一个边双连通分量 (e-DCC)。  
如果删掉一条边后图中的连通分量数增加了，则称这条边为桥或者割边。

此模板基于 [Tarjan算法](https://oi-wiki.org/graph/bcc/#%E8%BE%B9%E5%8F%8C%E8%BF%9E%E9%80%9A%E5%88%86%E9%87%8F) 实现了能计算极大 e-DCC 和桥的无向结构。

文件包含两个结构 `EDCC` 和 `EDCCGraph`, `EDCCGraph` 加完边后调用 `edcc()` 方法即可 $O(n+m)$ 求出 `EDCC`, 定义如下:

```cpp
struct EDCC {
    vector<vector<int>> groups;  // 将每个 e-DCC 的点各分一组存储
    vector<int> ids;             // 记录每个点属于哪个 edcc
    vector<bool> bridge;         // 记录每条边是否为桥
};
```
