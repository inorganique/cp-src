# Suffix Array (后缀数组)

## 用法

```cpp
vector<int> suffix_array(const Str &s)
```

返回 $n$ 长的数组 $sa$, $sa[i]=$ 字典序第 $i$ 小的后缀开头下标。

**参数要求**

- `Str` 可以是 `string`, `vector`, `deque`, `array` 等任何支持下标访问并且能用 `size(s)` 计算大小的容器。

**复杂度**

- $O(n\log n)$

<br>

### lcp_array

```cpp
vector<int> lcp_array(const Str &s, const vector<int> &sa)
```

返回 $\max(0,n)$ 长的数组 $lcp$, 其中 $lcp[i]=$ 后缀 $sa[i]$ 和 $sa[i+1]$ 的最大公共前缀。

**参数要求**
- `Str` 同上, `sa` 必须是 $s$ 的后缀数组

**复杂度**

- $O(n)$
