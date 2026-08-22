# KMP

## 用法

```cpp
vector<int> kmp(const Str &s)
```

返回 $n+1$ 长的数组 $pi$, $pi[i]=$ 前 $i$ 个字符组成的前缀 (即 $s[0...i-1]$) 的相同真前后缀的最大长度。

**参数要求**

- `Str` 可以是 `string`, `vector`, `deque`, `array` 等任何支持下标访问并且能用 `size(s)` 计算大小的容器。

**复杂度**
- $O(n)$

<br>

## 示例

```cpp
string s = "abcabcabc"s;
vector<int> pi = kmp(s);
for (int x : pi) {
    cout << x << " ";
}
cout << "\n";
```

**输出**

```
0 0 0 0 1 2 3 4 5 6 
```

<br>

可以计算 `kmp(t + '#' + s)` 判断 $t$ 出现在 $s$ 中的哪些位置。
