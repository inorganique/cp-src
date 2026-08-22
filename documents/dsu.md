# DSU (Disjoint Set Union, 并查集)

## 介绍

有 $n$ 个节点集合, 每个集合恰好有 $1$ 个节点, 节点编号为 $0, ..., n-1$, 你需要完成若干次操作, 每次操作是以下两种之一:

- 给定节点 $u$ 和 $v$, 将它们所在的集合合并
- 给定节点 $u$ 和 $v$, 判断是否属于同一个集合

<br>

对于该问题, 用 DSU 能高效完成每次操作。  
DSU 以树结构维护每个集合, 显然一开始每个节点的根都是自己。  
每个根节点可带信息, 比如树的大小, 合并树时可合并信息。

合并操作即为令一个根成为另一个根的子节点,  
如果随意指定合并方向, 操作的复杂度最差是 $O(n)$,  
采取以下任意一种优化方式, 就能优化到均摊 $O(\log n)$, 两种都采取为均摊 $O(\alpha(n))$

- 路径压缩: 往上找根时将路径上所有节点都接在根的下方
- 按秩合并: 总是令较大那棵树的根成为新根

某些问题用 DSU 合并树结构时, 两个根在合并后有明确的父子关系, 就不能按秩合并。

模板实现了 "路径压缩+按秩合并" 的并查集。

<br>

## 用法

### 构造

```cpp
DSU d(int n)
```

创建 $n$ 个节点集合。

**复杂度**

- $O(n)$

<br>

### leader

```cpp
int d.leader(int x)
```

返回 $x$ 的根。

**参数要求**
- $0 \le x \lt n$

**复杂度**
- $O(\alpha(n))$

<br>

### merge

```cpp
bool d.merge(int x, int y)
```

合并 $x$ 和 $y$ 所在的树。  
若 $x$ 和 $y$ 已经在同一棵树中, 则返回 `false`, 反之完成合并, 返回 `true`。

**参数要求**
- $0 \le x \lt n$
- $0 \le y \lt n$

**复杂度**
- $O(\alpha(n))$

<br>

### same

```cpp
bool d.same(int x, int y)
```

判断 $x, y$ 是否属于同一棵树。

**参数要求**
- $0 \le x \lt n$
- $0 \le y \lt n$

**复杂度**
- $O(\alpha(n))$

<br>

### size

```cpp
int d.size(int x)
```

返回 $x$ 所在树的节点数。

**参数要求**
- $0 \le x \lt n$

**复杂度**
- $O(\alpha(n))$

<br>

### groups

```cpp
vector<vector<int>> d.groups()
```

将每棵树中的节点存进一个 vector 并返回

**复杂度**
- $O(n)$

<br>
<br>

模板题: <https://atcoder.jp/contests/practice2/tasks/practice2_a>
