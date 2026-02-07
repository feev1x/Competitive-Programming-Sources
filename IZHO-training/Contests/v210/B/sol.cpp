#include <bits/stdc++.h>

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree(int n) : n(n) {
        t.resize(2 * n);
    }

    inline void update(int l, int r, int x) {
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                t[l++] += x;
            }

            if (r & 1) {
                t[--r] += x;
            }
        }
    }

    inline int get(int i) {
        int res = 0;

        for (i += n; i > 0; i >>= 1) {
            res += t[i];
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1), g2(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g2[u].emplace_back(v);
        g2[v].emplace_back(u);
    }

    std::vector<int> sub(n + 1), sub2(n + 1), tin(n + 1), tout(n + 1), tin2(n + 1), tout2(n + 1), pos(n + 1), pos2(n + 1);
    {
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            sub[v] = 1;

            for (auto to: g[v]) {
                if (to == p) {
                    continue;
                }

                self(self, to, v);

                sub[v] += sub[to];
            }
        };

        Dfs(Dfs, 1, 1);
    }

    {
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            sub2[v] = 1;

            for (auto to: g2[v]) {
                if (to == p) {
                    continue;
                }

                self(self, to, v);

                sub2[v] += sub2[to];
            }
        };

        Dfs(Dfs, 1, 1);
    }

    
    {
        int _t = -1;
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            std::sort(g[v].begin(), g[v].end(), [&](int i, int j) {
                return sub[i] < sub[j];
            });

            tin[v] = ++_t;
            pos[tin[v]] = v;

            for (auto to: g[v]) {
                if (to == p) {
                    continue;
                }

                self(self, to, v);
            }

            tout[v] = _t;
        };

        Dfs(Dfs, 1, 1);
    }

    {
        int _t = -1;
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            std::sort(g2[v].begin(), g2[v].end(), [&](int i, int j) {
                return sub2[i] < sub2[j];
            });

            tin2[v] = ++_t;
            pos2[tin2[v]] = v;

            for (auto to: g2[v]) {
                if (to == p) {
                    continue;
                }

                self(self, to, v);
            }

            tout2[v] = _t;
        };

        Dfs(Dfs, 1, 1);
    }

    auto Get = [&](int v, int i) {
        if (i + 1 == g[v].size()) {
            return sub[v];
        }

        return n - sub[g[v][i]];
    };

    auto Get2 = [&](int v, int i) {
        if (i + 1 == g2[v].size()) {
            return sub2[v];
        }

        return n - sub2[g2[v][i]];
    };

    std::vector<std::vector<std::tuple<int, int, int>>> upd(n + 1);
    auto Add = [&](int x, int y, int x2, int y2) {
        if (x > y || x2 > y2) {
            return;
        }

        upd[x].emplace_back(x2, y2, 1);
        upd[y + 1].emplace_back(x2, y2, -1);
    };

    g[1].emplace_back(1);
    g2[1].emplace_back(1);
    for (int v = 1; v <= n; ++v) {
        for (int j = 0, j2 = 0; j < g[v].size(); ++j) {
            if (v == 1 && j + 1 == g[v].size()) {
                break;
            }

            if (j + 1 == g[v].size()) {
                j2 = 0;
            }

            while (j2 + 1 < g2[v].size() && Get(v, j) <= Get2(v, j2)) {
                j2++;
            }

            if (j2 + 1 < g2[v].size()) {
                if (j + 1 == g[v].size()) {
                    Add(0, tin[v] - 1, tin2[g2[v][j2]], tout2[v]);
                    Add(tout[v] + 1, n - 1, tin2[g2[v][j2]], tout2[v]);
                } else {
                    Add(tin[g[v][j]], tout[g[v][j]], tin2[g2[v][j2]], tout2[v]);
                }
            }

            
            if (v != 1 && Get(v, j) > Get2(v, g2[v].size() - 1)) {
                if (j + 1 == g[v].size()) {
                    Add(0, tin[v] - 1, 0, tin2[v] - 1);
                    Add(0, tin[v] - 1, tout2[v] + 1, n - 1);
                    Add(tout[v] + 1, n - 1, 0, tin2[v] - 1);
                    Add(tout[v] + 1, n - 1, tout2[v] + 1, n - 1);
                } else {
                    Add(tin[g[v][j]], tout[g[v][j]], 0, tin2[v] - 1);
                    Add(tin[g[v][j]], tout[g[v][j]], tout2[v] + 1, n - 1);
                }
            }
        }
    }

    Segtree t(n);
    std::vector<int> ans(n + 1);
    for (int i = 0; i < n; ++i) {
        for (auto [l, r, x]: upd[i]) {
            t.update(l, r, x);
        }

        ans[pos[i]] = t.get(tin2[pos[i]]);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << ans[i] << " \n"[i == n];
    }

    return 0;
}
