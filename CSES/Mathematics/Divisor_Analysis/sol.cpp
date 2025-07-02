/**
 *    author:  feev1x
 *    created: 28.03.2025 16:11:17
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int64_t n) {
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
    
    int n; std::cin >> n;

    int cnt = 1, sum = 1, prod = 1;
    int c = 1;
    for (int i = 0; i < n; ++i) {
        int x, k; std::cin >> x >> k;

        prod = binpow(prod, k + 1);
        prod = mul(prod, binpow(binpow(x, (int64_t)k * (1 + k) / 2), c));

        cnt = mul(cnt, k + 1);
        c = (int64_t)c * (k + 1) % (MOD - 1);
        sum = mul(sum, divide((binpow(x, k + 1) - 1 + MOD) % MOD, x - 1));

    }

    std::cout << cnt << ' ' << sum << ' ' << prod << '\n';
    return 0;
}
