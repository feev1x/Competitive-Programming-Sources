#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;
 
inline void add_self(int &a, int b) {
    a += b;
 
    if (a >= MOD) {
        a -= MOD;
    }
 
    if (a < 0) {
        a += MOD;
    }
}
 
inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}
 
inline int binpow(int a, int n) {
    int res = 1;
 
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
 
        a = mul(a, a);
        n >>= 1;
    }
 
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }
 
    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i > 1; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }
 
    auto F = [&](int n, int k, int l) {
        return mul(fac[n], mul(mul(inv[k], inv[l]), inv[n - k - l]));
    };

    int res = 1;
    for (int i = 1; i < n; ++i) {
        int ans = 0;

        for (int j = 1; 2 * j <= i + 1; ++j) {
            int c1 = i + 1 - 2 * j, c0 = i - c1 - j;

            add_self(ans, F(i, c1, c0));
        }

        res = mul(res, ans);
    }

    std::cout << res << '\n';
    return 0;
}
