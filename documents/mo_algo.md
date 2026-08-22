# 莫队算法

## 介绍

对于 $n$ 长序列的 $q$ 个区间询问, 如果 $[l,r]$ 的答案能 $O(1)$ 扩展到 $[l+1,r]$, $[l,r-1]$, $[l-1,r]$, $[l,r+1]$ (即 $[l,r]$ 的相邻区间) 的答案,  
那么可以 $O(n\sqrt q)$ 求出所有询问的答案。

莫队算法基于分块思想对询问进行排序, 然后可以离线处理每个询问, 处理完上一个直接暴力地一步步转移到下一个区间的答案即可。

<br>

## 用法

```cpp
vector<int> mo_algo(int n, const vector<int> &lp, const vector<int> &rp)
vector<int> mo_algo(int n, const vector<pair<int, int>> &qs)
```

返回排序后的区间编号。

**参数要求**

- $n$ 是序列长度, 左右端点取值均为 $[0,n-1]$

- 左右端点分开存或用 `pair` 存都行

**复杂度**

- $O(q\log q)$

**示例**

```cpp

vector<int> a(n);

// 输入序列 a

vector<int> lp(q);
vector<int> rp(q);

// 输入 lp, rp

vector<int> order = mo_algo(lp, rp);

int l = 0;
int r = -1;
int ans = 0;

auto add = [&](int p) {
    // 这里写加入 a[p] 后怎么更新 ans
};
auto rem = [&](int p) {
    // 这里写移除 a[p] 后怎么更新 ans
};

for (int ii = 0; ii < q; ++ii) {
    int i = order[ii];
    // 建议先 add, 后 rem
    while (l > lp[i]) add(--l);
    while (r < rp[i]) add(++r);
    while (l < lp[i]) rem(l++);
    while (r > rp[i]) rem(r--);
    cout << ans << "\n";
}
```
