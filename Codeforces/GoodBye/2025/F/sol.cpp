#include <bits/stdc++.h>

inline int MOD = 998244353;

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

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> sub(n + 1);

    auto Dfs = [&](auto &&self, int v, int p) -> void {
        sub[v] = 1;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            if (sub[to] & 1) {
                sub[v] += sub[to];
            }
        }
    };

    Dfs(Dfs, 1, 1);

    std::vector<int> val;
    int res = 0, cnt = 0, fac = 1, ml = 1;
    for (int i = 2; i <= n; ++i) {
        if (sub[i] % 2 == 0) {
            cnt++;

            ml = mul(ml, sub[i]);
            val.emplace_back(sub[i]);
        }
    }

    if (cnt == 0) {
        std::cout << "1\n";
        return;
    }

    int fac1 = 1;

    for (int i = 2; i < cnt; ++i) {
        fac1 = mul(fac1, i);
    }

    for (auto u: val) {
        add_self(res, mul(mul(mul(ml, binpow(u, MOD - 2)), fac1), sub[1]));
    }

    std::cout << mul(res, ml) << '\n';
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
