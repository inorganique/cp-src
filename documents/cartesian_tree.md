# Cartesian Tree (笛卡尔树)

## 介绍

笛卡尔树是一种二叉树, 每个节点包含一个二元组 $(k,w)$, 要求:
- $k$ 满足二叉搜索树的性质 (中序遍历单调)
- $w$ 满足堆的性质。

某些问题的解法需要不断找序列中的最大/最小值, 然后朝左边和右边递归地计算答案, 非常适合用笛卡尔树解决。

此模板实现了根据序列 $v=v_0,v_1,...,v_{(n-1)}$ 构建笛卡尔树, $(k,w)=(i,v_i)$。

<br>

## 用法

```cpp
CartesianTree build_cartesian_tree(const vector<T> &v, Cmp cmp = {})
```

和 `std::priority_queue` 相同, `Cmp` 为 `less<T>` 时 $v_i$ 满足大根堆的性质, `greater<T>` 为小根堆。

返回一个 `CartesianTree` 结构体, 其定义如下:

```cpp
struct CartesianTree {
    int rt;           // 根
    vector<int> par;  // 父节点
    vector<int> ls;   // 左子节点 (不存在为 -1)
    vector<int> rs;   // 右子节点 (不存在为 -1)
};
```
