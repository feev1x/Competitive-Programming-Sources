/**
 *    author:  feev1x
 *    created: 28.03.2025 15:53:45
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


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; std::cin >> n;

    int sq = std::sqrt(n), res = 0;
    for (int i = 1; i <= sq; ++i) {
        add_self(res, mul(mul((n / i + 1) % MOD, n / i % MOD), (MOD + 1) / 2)); 
    }

    for (int i = 1; i <= sq; ++i) {
        int64_t x = n / i;

        if (x <= sq) {
            continue;
        }

        add_self(res, mul((x - sq) % MOD, i));
    }

    std::cout << res << '\n';
    return 0;
}
