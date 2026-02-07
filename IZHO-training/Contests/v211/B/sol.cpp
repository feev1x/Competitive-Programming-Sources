#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> sub(n + 1), tin(n + 1), tout(n + 1), dep(n + 1);
    std::vector<std::array<int, 20>> anc(n + 1);

    int _t = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        sub[v] = 1;
        tin[v] = ++_t;
        dep[v] = dep[p] + 1;
        anc[v][0] = p;

        for (int i = 1; i < 20; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);

            sub[v] += sub[to];
        }

        tout[v] = _t;
    };

    auto Lca = [&](int u, int v) {
        if (tin[u] <= tin[v] && tout[v] <= tout[u]) {
            return u;
        }

        for (int i = 19; i >= 0; --i) {
            int nx = anc[u][i];

            if (!(tin[nx] <= tin[v] && tout[v] <= tout[nx])) {
                u = nx;
            }
        }

        return anc[u][0];
    };

    auto Jump = [&](int u, int k) {
        for (int i = 0; i < 19; ++i) {
            if (k >> i & 1) {
                u = anc[u][i];
            }
        }

        return u;
    };

    int q; std::cin >> q;
    while (q--) {
        int r; std::cin >> r;

        int pr = 0;
        std::vector<int> rr(r);
        for (auto &u: r) {
            std::cin >> u;

            if (sub[pr] < sub[u]) {
                pr = u;
            }
        }

        int b; std::cin >> b;

        int pb = 0;
        std::vector<int> bb(b);
        for (auto &u: b) {
            std::cin >> u;

            if (sub[pb] < sub[u]) {
                pb = u;
            }
        }

        int lca = Lca(pb, pr);
        if (lca == pb) {
            
        } else if (lca == pr) {
        } else {
        }
    }

    return 0;
}
