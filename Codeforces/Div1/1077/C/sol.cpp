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
    std::vector<int> dep(n + 1), mxdep(n + 1), add(n + 1), ans(n + 1), all(n + 1), sub(n + 1);

    int64_t res = 0;
    auto Dfs = [&](auto &&self, int v) -> void {
        dep[v] = dep[p[v]] + 1;
        mxdep[v] = -1;
        sub[v] = 1;

        for (auto to: g[v]) {
            self(self, to);

            sub[v] += sub[to];

            if (mxdep[v] < mxdep[to]) {
                mxdep[v] = mxdep[to];

                std::swap(cnt[v], cnt[to]);
                std::swap(sum[v], sum[to]);
                std::swap(add[v], add[to]);
                std::swap(all[v], all[to]);
            }

            for (int i = 0; i < cnt[to].size(); ++i) {
                ans[v] += ((i + 1) * (cnt[to][i] + all[to] - (i ? cnt[to][i - 1] + all[to] : (int64_t)0))) * ((cnt[v].back() + all[v]) - (i ? cnt[v][i - 1] + all[v] : (int64_t)0));
                ans[v] += ((i + 1) * (cnt[to][i] + all[to] - (i ? cnt[to][i - 1] + all[to] : (int64_t)0))) * ((cnt[v][i] + all[v]) - (i ? cnt[v][i - 1] + all[v] : (int64_t)0));
            }

            for (int i = 1; i < cnt[to].size(); ++i) {
                ans[v] += (sum[v][i - 1] + add[v] * (cnt[v][i - 1] + all[v])) * (cnt[to][i] + all[to]);
            }

            if (cnt[to].size()) {
                all[v] += cnt[to].back();
                add[v] += sum[to].back() + (cnt[to].back() + all[to]);
            }

            for (int i = 0; i < cnt[to].size(); ++i) {
                cnt[v][i] += cnt[to][i] + all[to] - all[v] - cnt[to].back();
                sum[v][i] += sum[to][i] + (cnt[to][i] + all[to]) * add[to] - (cnt[to][i] + all[to]) * add[v] - sum[to].back() + (cnt[to].back() + all[to]);
            }
        }

        res += ans[v];
        mxdep[v]++;
        add[v]++;
        all[v]++;
        cnt[v].push_front(1 - all[v]);
        sum[v].push_front(-add[v]);
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
