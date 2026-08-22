# 二分

二分的实现很简单但是极易写错, 此模板仅提供整数域的二分。

实数域的二分可用精度作限制或直接指定循环次数。

<br>

## 用法

```cpp
ll find_first(ll lo, ll hi, Check f)
ll find_last(ll lo, ll hi, Check f)
```

`Check` 是形如 `bool(ll)` 的函数或 lambda 表达式。

`find_first` 需要 `Check` 满足: 存在整数 $p$, 使得 $i\lt p$ 时 `Check(i)` = false, $i\ge p$ 时 `Check(i)` = true, 返回值即为 $p$, 如果 $[lo,hi-1]$ 不存在这样的 $p$ 则返回 $hi$。

同理可得 `find_last` 对 `Check` 的要求, 如果 $[lo+1,hi]$ 不存在满足要求的 $p$ 则返回 $lo$。

<br>

## 示例

```cpp
vector<int> a = {0, 1, 2, 3, 4};
cout << find_first(0, 5, [&](ll i) { return a[i] >= 2; }) << "\n";
cout << find_last(0, 5, [&](ll i) { return a[i] <= 2; }) << "\n";
// 输出两个 2
```
