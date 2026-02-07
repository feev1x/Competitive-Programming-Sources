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

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::vector<int64_t> a(n + 1), bd(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::map<int64_t, int>> mp(n + 1);
    for (int i = 1; i <= n; ++i) { 
        std::cin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        int u, v; std::cin >> u >> v;

        mp[v][a[u]]++;
        if (a[v] > a[u]) {
            bd[v]++;
            g[u].emplace_back(v);
        }
    }

    std::queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (bd[i] == 0) {
            q.emplace(i);
        }
    }

    while (q.size()) {
        int v = q.front();

        q.pop();
        for (auto to: g[v]) {
            bd[to]--;

            add_self(mp[to][a[v]], mp[v][a[to] - a[v]]);

            if (bd[to] == 0) {
                q.emplace(to);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto [key, val]: mp[i]) {
            add_self(res, val);
        }
    }

    std::cout << res << '\n';
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
