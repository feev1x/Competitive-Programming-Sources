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
    int n; std::cin >> n; n++;
    std::vector<int> a(n), cnt(n);
    for (auto &u: a) {
        std::cin >> u;
        if (u > 0 && u < n) cnt[u]++;
        if (u >= n) cnt[0] = 2;
    }
    if (*std::max_element(cnt.begin(), cnt.end()) > 1) return std::cout << "0\n", void();
    int cn = 0;
    bool flag = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != -1) {
            if (a[i] == 0) continue;
            if (a[a[i]] == -1) a[a[i]] = i;
            if (a[a[i]] != i) flag = false;
        }
    }
    if (!flag || a[n - 1] == 0) return std::cout << "0\n", void();
    cn = std::count(a.begin(), a.end(), -1);
    if (a[0] == -1) cn--;
    std::vector<int> fac(n + 1, 1), inv(n + 1, 1), pr(n + 1);
    for (int i = 2; i <= n; ++i) fac[i] = mul(fac[i - 1], i);
    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i > 1; --i) inv[i] = mul(inv[i + 1], i + 1);
    pr[0] = 1;
    for (int i = 2; i <= n; i += 2) pr[i] = mul(mul(mul(pr[i - 2], i), i - 1), inv[2]);
    for (int i = 2; i <= n; i += 2) pr[i] = mul(pr[i], inv[i / 2]);
    int res = 0, res2 = 0;
    auto C = [&](int n, int k) { return mul(fac[n], mul(inv[n - k], inv[k])); };
    for (int i = 0; i * 2 <= cn; ++i) add_self(res, mul(binpow(2, cn - i * 2), mul(C(cn, i * 2), pr[i * 2])));
    if (a[n - 1] == -1) for (int i = 0; i * 2 <= cn - 1; ++i) add_self(res2, mul(binpow(2, cn - i * 2 - 1), mul(C(cn - 1, i * 2), pr[i * 2])));
    add_self(res, -res2);
    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
