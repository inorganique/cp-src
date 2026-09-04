# 一些数学函数 (除法取整, 快速幂, exgcd, 逆元, 中国剩余定理)

```cpp
ll absll(ll x)
```

标准库里的 `abs(ll)` 居然不是 `constexpr`, 所以我特地重写了一个。

<br>

```cpp
ll floor(ll x, ll y)
```

求 $\lfloor \dfrac x y \rfloor$

<br>

```cpp
ll ceil(ll x, ll y)
```

求 $\lceil \dfrac x y \rceil$

<br>

```cpp
ll bmod(ll x, ll y)
```

求 $x-\lfloor \dfrac x y \rfloor y$

<br>

```cpp
ll divmod(ll x, ll y)
```

求二元组 $(\lfloor \dfrac x y \rfloor, x-\lfloor \dfrac x y \rfloor y)$

<br>

```cpp
int powmod(ll x, ll n, int m)
```

$m$ 在 `int` 范围内的快速幂, 不解释

<br>

```cpp
ll powmodll(ll x, ll n, ll m)
```

$m$ 在 `ll` 范围内的快速幂, 不解释

<br>

```cpp
pair<ll, ll> exgcd(ll x, ll y)
```

扩展欧几里得算法, 求二元组 $(u, gcd)$, 其中 $gcd$ 是 $|x|, |y|$ 的最大公约数, $u$ 是满足 $u\cdot x+v\cdot y=gcd$ ($v$ 可以是任意整数) 的最小非负整数, 除非是特殊情况 $x<0且y=0$, 此时 $u=-1$。

<br>

```cpp
ll invmod(ll x, ll y)
```

求模 $y$ 意义下 $x$ 的逆元, 不存在逆元会 `assert` 中断。

<br>

```cpp
pair<ll, ll> crt(const vector<ll> &r, const vector<ll> &m)
```

求形如 $x \equiv r[i] (mod\ m[i])$ 的方程组的通解, 若有解, 其通解应是 $rem+k\cdot mod$, $k=0, 1, 2, ...$, 返回二元组 $(rem, mod)$, 无解返回 $(0, 0)$。
