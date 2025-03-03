/**
 *    author:  feev1x
 *    created: 26.02.2025 18:36:39
**/
#include <bits/stdc++.h>

struct Bit {
    std::vector<int64_t> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void add(int r, int x) {
        for (; r <= n; r += r & -r) {
            p[r] += x;
        }
    }

    inline int64_t get(int r) {
        int64_t res = 0;
        
        for (; r > 0; r -= r & -r) {
            res += p[r];
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1), tin(n + 1), tout(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    Bit bit(2 * n + 5);
    int _t = 1;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = _t++;

        bit.add(tin[v], a[v]);

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }

        tout[v] = _t++;

        bit.add(tout[v], -a[v]);
    };

    Dfs(Dfs, 1, 0);

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int v, x; std::cin >> v >> x;

            bit.add(tin[v], x - a[v]);
            bit.add(tout[v], a[v] - x);

            a[v] = x;
        } else {
            int v; std::cin >> v;

            std::cout << bit.get(tin[v]) << '\n';
        }
    }
    return 0;
}
