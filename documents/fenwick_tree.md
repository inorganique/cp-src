# Fenwick Tree (Binary Indexed Tree, 树状数组)

## 介绍

树状数组可以 $O(\log n)$ 实现单点加, 求前缀和, 还能借助其内部结构进二分 (具体看 `min_pref` 函数), 且常数很小。

<br>

## 用法

### 指定长度构造

```cpp
FenwickTree<T> ft(n);
```

长为 $n$ 的树状数组, 初始所有元素均为 `T{}`

**参数要求**

- `T` 可以是基本数据类型, 也可以是重载了 **加法** 和 **减法** 的自定义类型

**复杂度**

- $O(n)$

<br>

### 指定初始值构造

```cpp
// vector 存的类型不一定要和树状数组存的类型 T 一致, 只要能转化成 T 即可。
vector<int> a(n);
for (int i = 0; i < n; ++i) {
    cin >> a[i];
}
FenwickTree<ll> ft(a);
```

**复杂度**

- $O(n)$

<br>

### 单点加
```cpp
void ft.add(int p, T v);
```

**参数要求**

- $0\le p\le n$ ($p=n$ 无任何影响)

**复杂度**

- $O(\log n)$

<br>

### 前缀和

```cpp
T ft.get(int p)
```

**参数要求**

- $-1\le p\lt n$ ($p=-1$ 结果固定是 `T{}`)

**复杂度**

- $O(\log n)$

<br>

### 区间和

```cpp
T ft.sum(int l, int r)
```

求 $[l,r]$ 的和

**参数要求**

- $0\le l\le n$
- $-1\le r\lt n$
- $r-l+1\geq 0$ (可以令 $r=l-1$ 表示空区间)

<br>

### 树状数组上二分

```cpp
int ft.min_pref(check)
```

求满足 check 的最短前缀结尾下标, 要求存在点 $0\le p\lt n$ 使得 $i\lt p$ 时, `check(ft.get($i$))` 为 false, $i\geq p$ 时为 true, 返回值即为 $p$, 若全为 false 则返回 $n$。

**参数要求**

- check 是形如 bool(S) 的函数或 lambda 表达式

**复杂度**

- $O(\log n)$

**示例**

```cpp
vector<int> a = {1, 1, 1, 1, 1};
FenwickTree<ll> ft(a);
int p = ft.min_pref([](ll x) { return x >= 3; });
cout << p << "\n";  // 输出 2
```
