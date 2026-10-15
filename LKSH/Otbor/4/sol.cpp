#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }

inline int binpow(int a, int n) {
    int res = 1;
    while (n) { if (n & 1) res = mul(res, a); a = mul(a, a), n >>= 1; }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> ans(1 << n), fac(n + 1, 1);
    for (int i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    int res = 0;
    for (int mask = 1; mask < 1 << n; ++mask) {
        int gcd = 0;
        for (int i = 0; i < n; ++i) {
            if (mask >> i & 1) {
                gcd = std::__gcd(gcd, i + 1);
                int nmask = mask ^ (1 << i);
                if (ans[nmask] != 0 && (ans[mask] == 0 || ans[mask] > ans[nmask])) ans[mask] = ans[nmask];
            }
        }
        int ppc = __builtin_popcount(mask);
        if (ans[mask] == 0 && gcd == 1) ans[mask] = ppc;
        add_self(res, mul(ans[mask], mul(fac[ppc], fac[n - ppc])));
    }
    std::cout << res << '\n';
    return 0;
}
