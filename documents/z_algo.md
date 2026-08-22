# Z 函数 (扩展 kmp)

## 用法

```cpp
vector<int> z_algo(const Str &s)
```

返回 $n$ 长的数组 $z$, $z[i]=$ 以 $s[i]$ 开头的后缀和 $s$ 的最大公共前缀。

**参数要求**

- `Str` 可以是 `string`, `vector`, `deque`, `array` 等任何支持下标访问并且能用 `size(s)` 计算大小的容器。

**复杂度**

- $O(n)$
