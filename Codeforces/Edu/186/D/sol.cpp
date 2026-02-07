#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
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

inline void solve() {
    int n; std::cin >> n;

    std::map<int, int> mp;
    std::vector<int> a(n + 1), fac(n + 1, 1), inv(n + 1, 1);
    for (auto &u: a) {
        std::cin >> u;

        mp[u]++;
    }

    mp[a[0]]--;

    for (int i = 2; i <= n; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i >= 2; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }

    auto C = [&](int n, int k) {
        return mul(fac[n], mul(inv[k], inv[n - k]));
    };

    std::vector<std::pair<int, int>> pr;
    for (auto [key, val]: mp) {
        if (val == 0) {
            continue;
        }

        pr.emplace_back(key, val);
    }

    int64_t nd = 0;
    for (int i = 0; i + 1 < pr.size(); ++i) {
        nd += (pr.back().first - pr[i].first) * pr[i].second;
    }

    if (nd - a[0] > n - pr.back().second) {
        std::cout << "0\n";
        return;
    }

    if (nd - a[0] <= 0) {
        std::cout << fac[n] << '\n';
        return;
    }

    int sm = n - pr.back().second - (nd - a[0]);
    std::cout << mul(fac[pr.back().second + sm], mul(C(n - pr.back().second, sm), fac[n - pr.back().second - sm])) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
