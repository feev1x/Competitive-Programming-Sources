#include <bits/stdc++.h>
#include "grader.h"

int findEgg (int n, std::vector<std::pair<int, int>> bridges) {
    std::vector<int> fq, us;
    int nd = n;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<bool> used(n + 1);

    for (auto [u, v]: bridges) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto Dfs = [&](auto &&self, int v, int p) -> void {
        if (us.size() == nd) {
            return;
        }

        if (!used[v]) {
            fq.emplace_back(v);
            us.emplace_back(v);

            used[v] = true;
        } else {
            fq.emplace_back(v);
        }

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            if (us.size() == nd) {
                return;
            }

            self(self, to, v);
        }
    };

    while (true) {
        nd = 0;

        for (int i = 1; i <= n; ++i) {
            nd += !used[i];
        }

        nd = (nd + 1) / 2;

        Dfs(Dfs, 1, 0);

        int got = query(fq);

        if (got) {
            for (int i = 1; i <= n; ++i) {
                used[i] = true;
            }

            for (auto u: us) {
                used[u] = false;
            }

            if (us.size() == 1) {
                return us.front();
            }
        } else {
            int cnt = 0;

            for (int i = 1; i <= n; ++i) {
                cnt += !used[i];
            }

            if (cnt == 1) {
                for (int i = 1; i <= n; ++i) {
                    if (!used[i]) {
                        return i;
                    }
                }
            }
        }

        fq.clear();
        us.clear();
    }

    return -1;
}
