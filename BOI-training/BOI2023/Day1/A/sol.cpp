/**
 *    author:  feev1x
 *    created: 09.09.2025 12:10:21
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n), bad(n);
    std::vector<std::vector<bool>> mp(n), used(n);
    std::vector<int> p(n), mxd(n);
    std::vector<bool> a(n);
    for (int i = 1; i < n; ++i) {
        std::cin >> p[i];

        g[p[i]].emplace_back(i);
    }

    for (int i = 0; i < n; ++i) {
        short u; std::cin >> u;

        a[i] = u;
    }

    std::vector<int> d(n);
    std::vector<bool> ans(n);
    {
        auto Dfs = [&](auto &&self, const int &v) -> void {
            d[v] = d[p[v]] + 1;
            mxd[v] = d[v];

            mp.resize(1);

            if (a[v])
                mp[v][d[v] - d[v]] = true;

            std::vector<int> del;
            for (const auto &to: g[v]) {
                self(self, to);

                if (mxd[to] > mxd[v]) {
                    std::swap(mp[v], mp[to]);
                    std::swap(mxd[v], mxd[to]);
                    std::swap(d[v], d[to]);
                }
                
                used[v].resize(mxd[to] + 2);
            }

            for (const auto &to: g[v]) {

                if (mxd[v] < mxd[to]) {
                    std::swap(mp[v], mp[to]);
                    std::swap(mxd[v], mxd[to]);
                    std::swap(d[v], d[to]);
                }

                for (int dep = 0; dep <= mxd[to]; ++dep) {
                    int key = dep + d[to] - d[v];

                    if ((mp[v][key] & mp[to][dep]) && !used[v][mp[v][key]]) {
                        used[v][mp[v][key]] = true;
                        bad[v].emplace_back(key);
                    }

                    mp[v][key] = mp[v][key] | mp[to][dep];
                }
				
				mp[to].clear();
            }

            for (auto u: bad[v])
                mp[v][u] = 0;

            used[v].clear();
        };

        d[0] = -1;
        Dfs(Dfs, 0);
    }

    std::vector<int> cnt(n);
    auto Dfs = [&](auto &&self, const int &v) -> void {
        if (v)
            for (const auto &key: bad[v])
                cnt[key]++;

        if (a[v])
            ans[v] = !cnt[d[v]];

        for (const auto &to: g[v])
            self(self, to);

        if (v)
            for (const auto &key: bad[v])
                cnt[key]--;
    };

    Dfs(Dfs, 0);

    for (int i = 0; i < n; ++i)
        std::cout << (ans[i] ? d[i] : -1) << " \n"[i == n - 1];

    return 0;
}
