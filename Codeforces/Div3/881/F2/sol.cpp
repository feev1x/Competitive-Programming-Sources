/**
 *    author:  feev1x
 *    created: 30.06.2025 21:47:52
**/
#include <bits/stdc++.h>

struct Centroid {
    std::vector<int> sz, w, mxp, mx, mnp, mn, batya, smxp, smnp;
    std::vector<bool> del, ans;
    std::vector<std::vector<int>> g, temp;
    std::vector<std::array<int, 3>> q;
    int n, nw_sz, pref, pref1;

    Centroid(std::vector<std::vector<int>> _g, std::vector<std::array<int, 3>> _q, std::vector<int> _w) : g(_g), n(g.size() - 1), q(_q), w(_w) {
        sz.resize(n + 1);
        del.resize(n + 1);
        mxp.resize(n + 1);
        smxp.resize(n + 1);
        mx.resize(n + 1);
        mnp.resize(n + 1);
        smnp.resize(n + 1);
        mn.resize(n + 1);
        temp.resize(n + 1);
        batya.resize(n + 1);
        ans.resize(q.size());
    }

    inline void dfs(int v, int p) {
        sz[v] = 1;

        for (auto to: g[v]) {
            if (del[to] || to == p) {
                continue;
            }

            dfs(to, v);

            sz[v] += sz[to];
        }
    }

    inline int find(int v, int p) {
        for (auto to: g[v]) {
            if (del[to] || to == p) {
                continue;
            }

            if (sz[to] > nw_sz / 2) {
                return find(to, v);
            }
        }

        return v;
    }

    inline void calc(int v, int p) {
        batya[v] = batya[p];
        pref += w[v];
        pref1 += w[v];
        smxp[v] = std::max(pref1, smxp[p]);
        smnp[v] = std::min(pref1, smnp[p]);
        mxp[v] = std::max(pref, mxp[p]);
        mnp[v] = std::min(pref, mnp[p]);
        mx[v] = std::max(mx[p], pref - mnp[v]);
        mn[v] = std::min(mn[p], pref - mxp[v]);

        for (auto to: g[v]) {
            if (del[to] || to == p) {
                continue;
            }

            calc(to, v);
        }

        pref -= w[v];
        pref1 -= w[v];
    }

    inline void get(int v) {
        std::vector<int> idx(q.size());

        std::iota(idx.begin(), idx.end(), 0);
        get(v, idx);
    }

    inline void get(int v, std::vector<int> idx) {
        dfs(v, v);

        nw_sz = sz[v];
        v = find(v, v);

        smxp[v] = smnp[v] = 0;
        mxp[v] = mx[v] = std::max(0, w[v]);
        mnp[v] = mn[v] = std::min(0, w[v]);
        for (auto to: g[v]) {
            if (del[to]) {
                continue;
            }

            pref = w[v];
            pref1 = 0;
            batya[v] = to;
            calc(to, v);
        }

        for (auto i: idx) {
            if (q[i][0] == q[i][1]) {
                if (q[i][2] == w[q[i][0]] || q[i][2] == 0) {
                    ans[i] = true;
                }

                continue;
            }

            if (q[i][0] == v) {
                if (q[i][2] > 0) {
                    if (mx[q[i][1]] >= q[i][2]) {
                        ans[i] = true;
                    }
                } else {
                    if (mn[q[i][1]] <= q[i][2]) {
                        ans[i] = true;
                    }
                }

                continue;
            }

            if (q[i][1] == v) {
                if (q[i][2] > 0) {
                    if (mx[q[i][0]] >= q[i][2]) {
                        ans[i] = true;
                    }
                } else {
                    if (mn[q[i][0]] <= q[i][2]) {
                        ans[i] = true;
                    }
                }

                continue;
            }

            if (batya[q[i][0]] == batya[q[i][1]]) {
                temp[batya[q[i][0]]].emplace_back(i);
            } else {
                if (q[i][2] > 0) {
                    if (std::max({mx[q[i][1]], mx[q[i][0]], smxp[q[i][0]] + smxp[q[i][1]] + w[v], 0}) >= q[i][2]) {
                        ans[i] = true;
                    }
                } else {
                    if (std::min({mn[q[i][0]], mn[q[i][1]], smnp[q[i][0]] + smnp[q[i][1]] + w[v], 0}) <= q[i][2]) {
                        ans[i] = true;
                    }
                }
            }
        }

        del[v] = true;
        for (auto to: g[v]) {
            if (del[to]) {
                continue;
            }

            auto idx1 = temp[to];
            temp[to].clear();

            get(to, idx1);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> w{0, 1};
        std::vector<std::vector<int>> g(2);
        std::vector<std::array<int, 3>> q;
        for (int i = 1; i <= n; ++i) {
            std::string s; std::cin >> s;

            if (s == "+") {
                int v, x; std::cin >> v >> x;

                w.emplace_back(x);
                int u = g.size();

                g.resize(u + 1);
                g[u].emplace_back(v);
                g[v].emplace_back(u);
            } else {
                int u, v, k; std::cin >> u >> v >> k;

                q.push_back({u, v, k});
            }
        }

        Centroid c(g, q, w);

        c.get(1);

        for (auto u: c.ans) {
            std::cout << (u ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
