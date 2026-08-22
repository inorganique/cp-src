# HLD (Heavy Light Decomposition, 重链剖分)

重链剖分是将一棵树分成若干条链, 每个点恰好属于一条链, 根据每个点哪棵子树最大决定该节点要和谁连同一条链。

每个点到根节点最多经过 $O(\log n)$ 条链。

重链剖分通常用两次 dfs 实现, dfs1 统计每个点的 父节点, 深度, 子树大小, 重子节点; dfs2 统计每个点的 dfs 次序 (`dfn`), 链顶, 以及每个 dfs 次序是哪个点 (`ord`)。统计这 7 组信息即为重链剖分的整个过程。

每条链从链顶到链底的 `dfn` 都是连续的, 这是实现路径修改/查询等操作的关键。

此模板实现了有重链剖分功能的树结构。

<br>

## 用法

### 构造

```cpp
HLDTree tree(int n)
```

构建一棵 $n$ 个节点的树。

**复杂度**

- $O(n)$

<br>

### 加边

```cpp
void tree.add_edge(int u, int v)
```

**参数要求**

- $0\le u\lt n$
- $0\le v\lt n$
- $(u, v)$ 不能成环

**复杂度**

- $O(1)$

<br>

### 跑重链剖分

```cpp
void tree.hld(int rt)
```

**参数要求**

- $0\le rt\lt n$
- 此时必须已经加了 $n-1$ 条边且加的边必须组成一棵树

**复杂度**

- $O(n)$

<br>

### 根据 dfn 重排序列

```cpp
void tree.dfn_sort(vector<T> &v)
```

对于 $i=0,1,...,n-1$, 令 $t[dfn[i]]=v[i]$, 然后用 $t$ 替换 $v$。

**参数要求**

- $|v|=n$

<br>

### 找 LCA (最近公共祖先)

```cpp
int tree.lca(int u, int v)
```

**参数要求**

- $0\le u\lt n$
- $0\le v\lt n$

**复杂度**

- $O(\log n)$, 通常常数很小

<br>

### 路径操作

```cpp
int tree.apply(int u, int v, F f, bool includes_lca = true)
```

对 $u,v$ 两个端点的路径作某种操作, `includes_lca` 表示是否操作 lca, 最后将 lca 返回。

**参数要求**

- `F` 是形如 `void(int, int)` 的函数, 用来接收链顶和链底的 $dfn$, 可以搭配线段树使用。

示例: 求路径上的点权

```cpp
struct Info {
    ll sum = 0;
    friend Info operator+(Info a, Info b) {
        return {a.sum + b.sum};
    }
};

void solve() {
    // ...

    vector<int> weight(n);  // 点权

    // ...

    Segtree<Info> seg(weight);
    HLDTree tree(n);

    // ...

    ll ans = 0;
    tree.apply(u, v, [&](int l, int r) {
        ans += seg.query(l, r);
    });
    cout << ans << "\n";
}
```

如果题目给的不是点权而是边权, 可以把边权看成子节点的点权, 即每个点的点权为它到父节点的边的边权, 此时如果问 $u, v$ 路径的边权和, 就不应包含 lca。
