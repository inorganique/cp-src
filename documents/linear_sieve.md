# Linear Sieve (线性筛)

## 用法

```cpp
void sieve(int n)
```

可以筛出 $n$ 以内 (包括 $n$) 的质数并计算以下三个全局 `vector`:

- `lpf`: n 以内所有数的最小质因子
- `phi`: n 以内所有数的欧拉函数
- `mu `: n 以内所有数的莫比乌斯函数

`lpf` 是实现线性筛的必要信息, 如果题目不需要 `phi` 或 `mu` 可以将其删除。

**复杂度**

- $O(n)$

<br>

## 示例

```cpp
int main() {
    sieve(20);
    for (int i = 0; i < nprimes; ++i) {
        cout << primes[i] << " \n"[i == nprimes - 1];
    }
    for (int i = 1; i <= 20; ++i) {
        cout << lpf[i] << " \n"[i == 20];
    }
    for (int i = 1; i <= 20; ++i) {
        cout << phi[i] << " \n"[i == 20];
    }
    for (int i = 1; i <= 20; ++i) {
        cout << mu[i] << " \n"[i == 20];
    }
}
```

**输出**

```
2 3 5 7 11 13 17 19
0 2 3 2 5 2 7 2 3 2 11 2 13 2 3 2 17 2 19 2
1 1 2 2 4 2 6 4 6 4 10 4 12 6 8 8 16 6 18 8
1 -1 -1 0 -1 1 -1 0 0 1 -1 0 -1 1 1 0 -1 0 -1 0
```
