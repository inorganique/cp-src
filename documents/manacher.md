# Manacher

## 用法

```cpp
vector<int> manacher(const Str &s)
```

返回 $\max(0, 2n-1)$ 长的数组 $pal$, $pal[i]=$ 以位置 $\dfrac i 2$ 为中心的最大回文子串长度。

**参数要求**

- `Str` 可以是 `string`, `vector`, `deque`, `array` 等任何支持下标访问并且能用 `size(s)` 计算大小的容器。

**复杂度**
- $O(n)$
