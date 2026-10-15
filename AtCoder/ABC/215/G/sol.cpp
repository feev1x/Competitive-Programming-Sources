#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

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
    int n; std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;
        mp[u]++;
    }
    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i > 1; --i) inv[i] = mul(inv[i + 1], i + 1);
    auto C = [&](int n, int k) { return mul(fac[n], mul(inv[k], inv[n - k])); };
    std::vector<int> a;
    std::vector<std::pair<int, int>> b;
    for (auto [key, val]: mp) a.emplace_back(val);
    mp.clear();
    for (auto u: a) mp[u]++;
    for (auto [key, val]: mp) b.emplace_back(key, val);
    for (int k = 1; k <= n; ++k) {
        int res = 0;
        for (auto [key, val]: b) {
            add_self(res, mul(val, C(n, k)));
            if (k <= n - key) add_self(res, -mul(val, C(n - key, k)));
        }
        std::cout << mul(res, mul(mul(fac[n - k], fac[k]), inv[n])) << '\n';
    }
    return 0;
}
