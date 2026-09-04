# 模 P 下的多项式乘法

## 介绍

此模板能在 $O(k 2^k)$ 的时间求出模 $P$ 下两个多项式 $a, b$ 的乘积。  
其中 $k= \lceil\log_2\max(|a|, |b|)\rceil$

<br>

## 用法

### 就这一个核心函数

```cpp
vector<int> convolve(const vector<int> &a, const vector<int> &b)
```

**参数要求**

a, b 长度任意, 存的 int 在输入的时候可能 $\ge P$, 务必要求卷积前对 $P$ 取模。

`primitive_root_constexpr`, `ntt`, `addm`, `mulm` 以及从 math.cpp 复制过来的函数都是为 `convolve` 服务的, 由 `convolve` 自动调用, 不需要手动使用。

已 AC [AtCoder 的模板题](https://atcoder.jp/contests/practice2/submissions/78949084), 应该可以放心使用 ლ(╹◡╹ლ)
