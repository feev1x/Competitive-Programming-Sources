#include <bits/stdc++.h>

inline void solve() {
    int n, k, v; std::cin >> n >> k >> v;

    std::vector<int> lf(n + 1, k);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    auto Dfs = [&](auto &&self, int v, int p, int cd) -> bool {
        if (g[v].size() == 1 && g[v][0] == p) {
            return true;
        }

        int pos = -1;
        std::vector<int> gv;
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i];

            if (to == p) {
                continue;
            }

            if (self(self, to, v, cd - 1)) {
                if (cd > 0) {
                    return true;
                }

                gv.emplace_back(0);
                lf[v] = 0;
                pos = i;
                cd = k;
                break;
            }

            gv.emplace_back(lf[to] + 1);

            lf[v] = std::min(lf[v], lf[to] + 1);
        }

        if (pos != -1) {
            gv.clear();

            for (int i = 0; i < g[v].size(); ++i) {
                int to = g[v][i];

                if (to == p || pos == i) {
                    if (pos == i) {
                        gv.emplace_back(0);
                    }

                    continue;
                }

                if (self(self, to, v, cd - 1)) {
                    return true;
                }

                gv.emplace_back(lf[to] + 1);
            }
        }
        
        std::sort(gv.begin(), gv.end());

        if (gv.size() > 1) {
            if (gv[0] + gv[1] < k) {
                return true;
            }
        }

        return false;
    };

    std::cout << (Dfs(Dfs, v, v, 0) ? "YES" : "NO") << '\n';
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
