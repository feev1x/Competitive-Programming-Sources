/**
 *    author:  feev1x
 *    created: 26.03.2025 16:07:02
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, MOD1 = 1e9 + 6;

inline int mul(int a, int b, int mod) {
    return (int64_t)a * b % mod;
}

inline int binpow(int a, int n, int mod) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a, mod);
        }

        a = mul(a, a, mod);
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    while (n--) {
        int a, b, c; std::cin >> a >> b >> c;

        std::cout << binpow(a, binpow(b, c, MOD1), MOD) << '\n';
    }
    return 0;
}
