/**
 *    author:  feev1x
 *    created: 29.03.2025 19:19:38
**/
#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
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

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<int> a(n), fac(k + 1);
    for (auto &u: a) {
        std::cin >> u;
    }

    fac[0] = 1;
    for (int i = 1; i <= k; ++i) {
        inv[i] = binpow(i, MOD - 2);
        fac[i] = mul(fac[i - 1], i);
    }

    auto C = [&](int N, int K) {
        return divide(fac[N], mul(fac[K], fac[N - K]));
    };

    int sum1 = 0;
    std::vector<int> sum(k + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {

        }

        add_self(sum1, mul(i + 1, a[i]));
        for (int j = 0; j <= k; ++j) {
            sum[j] = ;
        }
    }
    return 0;
}
