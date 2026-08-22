vector<int> lpf;
vector<int> phi;
vector<int> mu;
vector<int> primes;

void sieve(int n) {
    lpf.resize(n + 1);
    phi.resize(n + 1, 1);
    mu.resize(n + 1, 1);
    primes.clear();
    for (int i = 2; i <= n; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            phi[i] = i - 1;
            mu[i] = -1;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > lpf[i] || i * p > n) {
                break;
            }
            lpf[p * i] = p;
            phi[p * i] = phi[i] * (p == lpf[i] ? p : p - 1);
            mu[p * i] = (p == lpf[i] ? 0 : -mu[i]);
        }
    }
}
