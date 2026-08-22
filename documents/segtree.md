# Segtree (线段树)

## 介绍

线段树递归地把大区间一分为二, 分成很多小区间，让程序可以在 $O(\log n)$ 的时间内完成查找和更新。

模板实现了单点改, 区间查, 不支持区间改的线段树, 支持树上二分。

<br>

## 用法

### 指定长度构造

```cpp
Segtree<Info> seg(int n)
```

**参数要求**

`Info` 必须是像这样定义的结构体:

```cpp
struct Info {
    // 成员变量
    friend Info operator+(Info a, Info b) {
        // 合并信息
    }
};
```
必须保证 `Info` 的默认值和另一个 `Info` 合并结果仍是另一个 `Info`

**复杂度**

- $O(n)$

<br>

### 指定初始值构造

```cpp
Segtree<Info> seg(const vector<T> &a)
```

**参数要求**

- T 能通过 `Info(T)` 显式转化成 Info

**复杂度**

- $O(n)$

<br>

### 单点改

```cpp
void seg.set(int p, Info v)
```

**参数要求**

- $0\le p \lt n$

**复杂度**

- $O(\log n)$

<br>

### 单点改

```cpp
Info seg.get(int p)
```

**参数要求**

- $0\le p \lt n$

**复杂度**

- $O(1)$

<br>

### 区间查

查询 $[l,r]$ 的结果。

```cpp
Info seg.query(int l, int r)
```

**参数要求**

- $0\le l\le n$
- $-1\le r\lt n$
- $r-l+1\geq 0$ (可以令 $r=l-1$ 表示空区间)

**复杂度**

- $O(\log n)$

<br>

### 树上二分

```cpp
int seg.min_r(int l, Check g)
int seg.max_l(int r, Check g)
```

`min_r` 能找到最小的 $r$ 使得 $l\le r$ 且 `g(seg.query(l, r))` 为 true, 前提是能二分, 如果没有 $r\in [l,n-1]$ 满足条件就返回 $n$。  
同理 `max_l` 是找 $l$, 找不到返回 $-1$。

**参数要求**

- $0\le l\le n$
- $-1\le r\lt n$

**复杂度**

- $O(\log n)$
