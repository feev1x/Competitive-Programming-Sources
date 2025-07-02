/**
 *    author:  feev1x
 *    created: 13.06.2025 14:17:02
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n, k; std::cin >> n >> k;
 
        std::vector<int64_t> p(n), d(n);
 
        for (auto &u: p) {
            std::cin >> u;
        }
 
        for (auto &u: d) {
            std::cin >> u;
        }

        std::map<int64_t, std::vector<int>> mp, mp1;
        std::vector<int> l(n, -1), r(n, -1);
        std::map<int64_t, int> idx;
        std::vector<std::array<bool, 2>> go(n, std::array<bool, 2>{false, false});
        std::vector<std::array<bool, 2>> used(n, std::array<bool, 2>{false, false});

        for (int i = 0; i < n; ++i) {
            mp[((d[i] - p[i]) % k + k) % k].emplace_back(p[i]);
            mp1[((d[i] + p[i]) % k + k) % k].emplace_back(p[i]);

            idx[p[i]] = i;
        }


        for (int i = 0; i < n; ++i) {
            auto it = std::lower_bound(mp[((d[i] - p[i]) % k + k) % k].begin(), mp[((d[i] - p[i]) % k + k) % k].end(), p[i]);
            auto it1 = std::lower_bound(mp1[((d[i] + p[i]) % k + k) % k].begin(), mp1[((d[i] + p[i]) % k + k) % k].end(), p[i]);

            if (it1 != mp1[((d[i] + p[i]) % k + k) % k].begin()) {
                --it1;

                l[i] = idx[*it1];

                ++it1;
            }

            ++it;

            if (it != mp[((d[i] - p[i]) % k + k) % k].end()) {
                r[i] = idx[*it];
            }
        }

        auto Dfs = [&](auto &&self, int v, bool fl) -> void {
            used[v][fl] = true;

            if (fl) {
                if (r[v] == -1) {
                    go[v][fl] = true;
                    return;
                }

                if (!used[r[v]][!fl]) {
                    self(self, r[v], !fl);
                }

                go[v][fl] = go[r[v]][!fl];
            } else {
                if (l[v] == -1) {
                    go[v][fl] = true;
                    return;
                }

                if (!used[l[v]][!fl]) {
                    self(self, l[v], !fl);
                }

                go[v][fl] = go[l[v]][!fl];
            }
        };

        for (int i = 0; i < n; ++i) {
            if (!used[i][0]) {
                Dfs(Dfs, i, 0);
            }

            if (!used[i][1]) {
                Dfs(Dfs, i, 1);
            }

//            std::cout << go[i][0] << ' ' << go[i][1] << '\n';
        }
 
        int q; std::cin >> q;
        while (q--) {
            int64_t pos; std::cin >> pos;

            auto it = std::lower_bound(mp[((-pos) % k + k) % k].begin(), mp[((-pos) % k + k) % k].end(), pos);

            if (it == mp[((-pos) % k + k) % k].end()) {
                std::cout << "YES\n";

                continue;
            }

            int i = idx[*it];

            std::cout << (go[i][0] ? "YES\n" : "NO\n");
        }
    }

    return 0;
}
