#include <bits/stdc++.h>

#define int int64_t

constexpr int MOD = 998244353;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> a(n + 1), b(n + 1), ans(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int j = 1; j <= n; ++j) {
        std::cin >> b[j];
    }

    for (int gcd = 1; gcd <= n; ++gcd) {
        for (int i = gcd; i <= n; i += gcd) {
            for (int lcm = i; lcm + gcd <= n; lcm += i) {
                int j = lcm / i * gcd;

                if (j > n || j < 1) {
                    continue;
                }

                if (std::gcd(i, j) == gcd && std::lcm(i, j) == lcm) {
                    add_self(ans[gcd + lcm], mul(a[i], b[j]));
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }

    return 0;
}
