# 懒标线段树

功能最强大的数据结构之一, 支持区间改, 区间查, 树上二分。

<br>

## 用法

### 指定长度构造

```cpp
LazySegtree<Info, Tag> tree(n)
```

必须像这样定义 `Info` 和 `Tag`:

```cpp
struct Tag {
    // 成员变量
    void apply(Tag newtag) {
        // 新标记怎么影响当前标记
        // 例如: 如果是区间加, 则标记相加, 如果是区间赋值, 则直接覆盖
    }
};

struct Info {
    // 成员变量
    void apply(Tag f) {
        // 用标记更新信息
    }
    friend Info operator+(Info a, Info b) {
        // 信息合并
    }
};
```

必须保证 `Info` 的默认值和另一个 `Info` 合并结果仍是另一个 `Info`  
必须保证 `Tag` 默认值被 `Info` 和 `Tag` `apply` 时无任何影响。

**复杂度**

- $O(n)$

<br>

### 指定初始值构造

```cpp
LazySegtree<Info, Tag> tree(const vector<T> &a)
```

**参数要求**

- T 能通过 `Info(T)` 显式转化成 Info

**复杂度**

- $O(n)$

<br>

### 单点改

```cpp
void tree.set(int p, const Info &s)
void tree.apply(int p, const Tag &f)
```

可以用 `Tag` 修改单个值了, 效果和 `tree.apply(p, p, f)` 相同。

**参数要求**

- $0\le p\lt n$

**复杂度**

- $O(\log n)$

<br>

### 单点查

```cpp
Info tree.get(int p)
```

**参数要求**

- $0\le p\lt n$

**复杂度**

- $O(\log n)$, 因为涉及标记下传, 所以不是和普通线段树一样的 $O(1)$

<br>

### 区间改

```
void tree.apply(int l, int r, const Tag &f)
```

**参数要求**

- $0\le l\le n$
- $-1\le r\lt n$
- $r-l+1\geq 0$ (可以令 $r=l-1$ 表示空区间)

**复杂度**

- $O(\log n)$

<br>

### 区间查

和普通线段树基本一致, 此处省略。

### 树上二分

和普通线段树基本一致, 此处省略。
