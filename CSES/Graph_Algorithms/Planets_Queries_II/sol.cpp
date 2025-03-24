/**
 *    author:  feev1x
 *    created: 04.03.2025 00:12:59
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    int n;

    Dsu(int _n) : n(_n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            p[u] = v;
            sz[v] += sz[u];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Dsu d(n);
    std::vector<bool> used(n + 1), cyc(n + 1);
    std::vector<int> p(n + 1), head(n + 1), sz(n + 1), idx(n + 1), dis(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::array<int, 18>> anc(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        anc[i][0] = p[i];
        g[p[i]].emplace_back(i);
        d.unite(i, p[i]);
    }

    for (int j = 1; j < 18; ++j) {
        for (int i = 1; i <= n; ++i) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        int u = i, cnt = 0;
        while (!used[u]) {
            used[u] = true;

            u = p[u];
        }
        
        int _t = 1;
        for (int v = p[u]; ; v = p[v]) {
            head[v] = v;
            idx[v] = _t++;
            cyc[v] = true;
            cnt++;

            if (v == u) {
                break;
            }
        }

        for (int v = p[u]; ; v = p[v]) {
            sz[v] = cnt;
            dis[v] = 0;
            
            std::queue<int> qq;

            qq.emplace(v);
            while (qq.size()) {
                int u = qq.front();

                qq.pop();
                for (auto to: g[u]) {
                    if (cyc[to]) {
                        continue;
                    }

                    dis[to] = dis[u] + 1;
                    head[to] = v;
                    used[to] = true;

                    qq.emplace(to);
                }
            }

            if (v == u) {
                break;
            }
        }
    }

    auto Anc = [&](int v, int k) {
        for (int i = 0; i < 18; ++i) {
            if (k >> i & 1) {
                v = anc[v][i];
            }
        }

        return v;
    };

    while (q--) {
        int u, v; std::cin >> u >> v;

        if (u == v) {
            std::cout << "0\n";

            continue;
        }

        if (d.get(u) != d.get(v) || !cyc[v] && (cyc[u] || head[u] != head[v] || dis[u] <= dis[v] || Anc(u, dis[u] - dis[v]) != v)) {
            std::cout << "-1\n";

            continue;
        }

        if (!cyc[v]) {
            std::cout << dis[u] - dis[v] << '\n';
        } else {
            if (idx[head[u]] > idx[v]) {
                std::cout << dis[u] + idx[v] + sz[v] - idx[head[u]] << '\n';
            } else {
                std::cout << dis[u] + idx[v] - idx[head[u]] << '\n';
            }
        }
    }
    return 0;
}
