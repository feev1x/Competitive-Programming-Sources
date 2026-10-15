#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::vector<int> p(n + 1);
    std::vector<std::vector<int>> g(n + 1);

    std::iota(p.begin(), p.end(), 1);
    p[n] = n;
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        
        p[u] = std::max(p[u], v);
    }

    for (int i = 1; i < n; ++i) {
        g[p[i]].emplace_back(i);
    }

    std::vector<std::deque<int>> cnt(n + 1), sum(n + 1);

    int64_t res = 0;
    auto Dfs = [&](auto &&self, int v) -> void {
        dep[v] = dep[p[v]] + 1;
        mxdep[v] = -1;

        for (auto to: g[v]) {
            self(self, to);

            if (mxdep[v] < mxdep[to]) {
                std::swap(cnt[v], cnt[to]);
                std::swap(sum[v], sum[to]);
                std::swap(mxdep[v], mxdep[to]);
            }

            for (int i = 0; i < cnt[to].size(); ++i) {
                res += ;
            }

            for (int i = 0; i < cnt[to].size(); ++i) {
                cnt[v][i] += cnt[to][i];
                sum[v][i] += sum[to][i];
            }
        }

        mxdep[v]++;
        cnt[v].push_front(1);
        if (sum[v].size()) sum[v].push_front(sum.front() + 1);
        else sum[v].push_front(1);
    };

    dep[n] = 1;
    Dfs(Dfs, n);

    std::cout << res << '\n';
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
