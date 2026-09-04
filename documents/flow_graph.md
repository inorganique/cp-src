# 最大流/最小割

## 介绍

什么是从源点 $s$ 到汇点 $t$ 的最大流? 对于无权图, 其值等于从 $s$ 到 $t$ 的边集互不相交的路径个数。对于有权图, 将每条权值为 $w$ 的边看成 $w$ 条无权的重边理解即可。网络流问题中的权值一般称为 "容量"。

什么是最小割? 割是为一种点的划分方式: 将所有的点划分为点集 $S$ 和其补集 $T=V-S$, 其中源点 $s\in S$, 汇点 $t\in T$, 定义割 $(S, T)$ 的容量 $c(S, T)$ 表示所有从 $S$ 到 $T$ 的边的容量之和。

最小割就是求一个割使容量最小。

**重要结论: 最大流=最小割容量**

<br>

## 用法

### 构造

```cpp
FlowGraph<Cap> fg(int n)
```

创建 $n$ 个点的网络流图, 容量类型为 `Cap`, 最常用的是 `long long`。

<br>

### add_edge

```cpp
void fg.add_edge(int u, int v, Cap c)
```

建一条从 $u$ 到 $v$, 容量为 $c$ 的边。

**参数要求**

- $0\le u\lt n$
- $0\le v\lt n$
- $0\le c$

**复杂度**

- $O(1)$

<br>

### flow

```cpp
Cap fg.flow(int s, int t)
```

**复杂度**

- $O(\min(n^{\frac 2 3}m, m^{\frac 3 2}))$ 所有边容量为 $1$
- $O(n^2 m)$ 其他

**参数要求**

- $0\le s\lt n$
- $0\le t\lt n$
- $s\ne t$

<br>

### min_cut

```cpp
vector<bool> fg.min_cut(int s)
```

必须先调用 `Cap fg.flow(int s, int t)`  
在跑完最大流的图上求最小割, 返回的第 $i$ 个元素是 `true`, 则节点 $i\in S$, 否则 $i\in T$。

**参数要求**

$s$ 必须等于刚才调用 `flow` 时的 $s$

**复杂度**

- $O(n+m)$
