# 点双连通分量

## 介绍

对于一个无向图, 如果删除任何一个点及其所有相关的边, 都不能使得 $u, v$ 两个点不连通, 则 $u, v$ 属于同一个点双连通分量 (v-DCC)。  
如果删掉一个点后图中的连通分量数增加了，则称这个点为割点。

此模板基于 [Tarjan算法](https://oi-wiki.org/graph/bcc/#%E7%82%B9%E5%8F%8C%E8%BF%9E%E9%80%9A%E5%88%86%E9%87%8F) 实现了能计算极大 v-DCC 和割点的无向结构。

文件包含两个结构 `VDCC` 和 `VDCCGraph`, `VDCCGraph` 加完边后调用 `vdcc()` 方法即可 $O(n+m)$ 求出 `VDCC`, 定义如下:

```cpp
struct VDCC {
    vector<vector<int>> groups;  // 将每个 v-DCC 的点各分一组存储
    vector<bool> cut;            // 记录每个点是否为割点
};
```
