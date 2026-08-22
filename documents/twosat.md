# 2-SAT (2-Satisfiability)

## 介绍

2-SAT 是一种 "布尔可满足性问题", 它包含 $n$ 个 bool 变量和 $m$ 个限制条件，每个条件形如 $(x = vx)\lor(y = vy)$, $vx$ 和 $vy$ 是 bool 值, 最终目标是给每个变量赋值 $true$ 或 $false$ 让所有条件都成立。

2-SAT 可借助有向图的强连通分量 (SCC) 线性解决, 大致流程是:  
创建有 $2n$ 个点的有向图, 对于限制 $(x = vx)\lor(y = vy)$, 加边 $2x+$!$vx\rarr 2v+vy$ 和 $2v+$!$vy\rarr 2x+vx$,  

我的 scc 模板如果编号为 $i$ 的 scc 能到达 $j$, 则必有 $i\lt j$。

如果 $2x$ 所在 scc 的编号比 $2x+1$ 的更大, 则 $x=false$, $2x+1$ 的更大就是 $true$, 如果一样大则无解。

<br>

## 用法

***此模板依赖 SCC 模板实现, 将 SCC 放其在上方才能正常使用***

### 构造

```cpp
explicit TwoSAT(int n)
```

创建 $n$ 个 bool 变量, 一开始没有任何限制。

<br>

### add_clause

```cpp
void add_clause(int x, bool vx, int y, bool vy)
```

添加限制 $(x = vx)\lor(y = vy)$

**参数要求**
- $0 \le x \lt n$
- $0 \le y \lt n$

<br>

### solve

```cpp
optional<vector<bool>> TwoSAT::solve()
```

加完限制后调用即可解决 2-SAT 问题。

`optional<T>` 是标准库的类模板, 内部包含一个 bool 和一个 T, 用来表示 "可能存在, 也可能不存在" 的值, 可直接放进 `if` 判断, 如果有值, 可用 `*` 获得其值, 示例:

```cpp
TwoSAT ts(n);

// ...加限制...

auto res = ts.solve();
if (!res) {
    cout << "无解\n";
} else {
    cout << "有解\n";
    vector<bool> &ans = *res;  // 来个引用, 省得后面再写 *
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}
```
