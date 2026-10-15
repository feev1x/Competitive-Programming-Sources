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

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
