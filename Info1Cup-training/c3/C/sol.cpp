/**
 *    author:  feev1x
 *    created: 30.01.2025 10:46:27
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

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

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, w, k, x, y; std::cin >> n >> w >> k >> x >> y;

    int sum = 0;
    for (int i = 0; i < w; ++i) {
        int u; std::cin >> u;

        add_self(sum, u);
    }
    
    std::cout << mul(binpow(sum, n), binpow(n, k)) << '\n';
    return 0;
}
