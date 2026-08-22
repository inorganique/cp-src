# SCC (Strong Connected Component, 强连通分量)

## 介绍

对于一个有向图, 如果点 $u, v$ 能相互到达, 则 $u, v$ 属于同一 scc, 任何一条回路都是 scc。

如果有向图的一个子图内任意两个顶点都互相可达 (能从 $u$ 到 $v$，也能从 $v$ 到 $u$), 且无法再加入任何一个点保持这个性质，它就是一个极大 scc。显然每个点恰好属于一个极大 scc。

如果把图中每个 scc 合并成一个点, 把原图中两点不属于同一 scc 的边分别连到两个 scc 合并出的点上, 原本有环的复杂有向图会变成一个有向无环图 (DAG), 这能简化统计或 dp 等问题。

此模板基于 [Tarjan算法](https://oi-wiki.org/graph/scc/#tarjan-%E7%AE%97%E6%B3%95) 实现了能计算极大 scc 的有向图结构。

如果缩点后编号为 $i$ 的 scc 能到达 $j$, 则必有 $i\lt j$。

<br>

## 用法

### 构造

```cpp
SCCGraph sg(int n)
```

创建 $n$ 个点的有向图

**复杂度**

- $O(n)$

<br>

### add_edge

```cpp
void sg.add_edge(int from, int to)
```

连一条从 $from$ 到 $to$ 的有向边

**参数要求**

- $0\leq u\lt n$
- $0\leq v\lt n$

**复杂度**

- $O(1)$


<br>

### scc_ids

```cpp
pair<int, vector<int>> sg.scc_ids()
```

返回值的 first 是极大 scc 个数, second 是长 $n$ 的 vector, 记录每个点所属的 scc 编号。

**复杂度**

- $O(n)$

<br>

### scc

```cpp
SCC sg.scc()
```

内部调用 scc_ids, 根据每点所属编号生成二维 vector, 记录每个编号的 scc 包含哪些点, 最后将二者一并返回。`SCC` 定义如下:

```cpp
struct SCC {
    vector<vector<int>> groups;
    vector<int> ids;
};
```
