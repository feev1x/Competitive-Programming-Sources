#include <bits/stdc++.h>

constexpr int MOD = 676767677;

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
    int n, m; std::cin >> n >> m;
    std::vector<int> fac(n + m + 1, 1), inv(n + m + 1, 1);
    for (int i = 2; i <= n + m; ++i) fac[i] = mul(fac[i - 1], i);
    inv[n + m] = binpow(fac[n + m], MOD - 2);
    for (int i = n + m - 1; i > 1; --i) inv[i] = mul(inv[i + 1], i + 1);
    auto C = [&](int n, int k) { return mul(fac[n], mul(inv[k], inv[n - k])); };
    int cnt = 0, res = 0;
    for (int ls = 0; ls < m; ++ls) add_self(cnt, C(n + ls - 1, n - 1));
    std::vector<int> ans(n + 1, -1);
    auto Sum = [&](int x) {
        if (ans[x] != -1) return ans[x];
        int cn = 0;
        for (int ls = 0; ls < m; ++ls) add_self(cn, C(n + ls - 1 - x, n - 1 - x));
        return ans[x] = cn;
    };
    auto Get = [&](auto &&self, int l, int r, int c) -> void {
        if (l > r) return;
        int mid = l + r >> 1;
        int szl = mid - l + 1, szr = r - mid + 1, cn = 0;
        if (l == 1 && r == n) cn = 0;
        else if (l == 1) cn = Sum(szr);
        else if (r == n) cn = Sum(szl);
        else {
            cn = Sum(szr);
            add_self(cn, Sum(szl));
            add_self(cn, -Sum(szl + szr));
        }
        add_self(res, mul(c, (cnt - cn + MOD) % MOD));
        self(self, l, mid - 1, c + 1);
        self(self, mid + 1, r, c + 1);
    }; Get(Get, 1, n, 1);
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
