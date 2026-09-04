constexpr int K = 50;       // 输入数字最多有 K 位, 即小于 2^K
using Typ = long long;      // 根据 K 选择 int, unsigned, long long 等类型
using Arr = array<Typ, K>;  // 我喜欢用 array, 也可以换成别的容器表示线性基

// 尝试向线性基插入数字, 返回 true 或 false 表示是否插入成功
// 注意: array 如果不进行初始化会包含随机数据
// 一定一定一定要确保初始全 0, 例:
// Arr a = {};
bool insert(Arr &a, Typ x) {
    for (int i = K - 1; i != -1; --i) {
        if ((x >> i & 1) == 0) {
            continue;
        }
        if (a[i] == 0) {
            a[i] = x;
            return true;
        }
        x ^= a[i];
    }
    return false;
}
