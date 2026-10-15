#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }
inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a), n >>= 1;
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k, res = 0; std::cin >> n >> k; std::swap(n, k);
    std::vector<int> fac(2 * n + 1, 1), inv(2 * n + 1, 1);
    for (int i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 2; --i) inv[i] = mul(inv[i + 1], i + 1);
    auto C = [&](int n, int k) { return mul(fac[n], mul(inv[k], inv[n - k])); };
    for (int r = std::max(k, (n + 1) / 2); r <= n; ++r) {
        add_self(res, C(n, r));
        if (2 * r - n < k && 2 * r - n) add_self(res, -C(n, r - ((n - r) - (k - (2 * r - n))) + (2 * r - n + 1)));
        else if (!(2 * r - n)) add_self(res, -C(n, r - 1));
        std::cout << res << '\n';
    }
    std::cout << res << '\n';
    return 0;
}
