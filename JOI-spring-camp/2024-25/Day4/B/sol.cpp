#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> p(n + 1), k(n + 1), tin(n + 1), tout(n + 1), d(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::multiset<std::pair<int, int>>> dep(n + 1);
    for (int i = 2; i <= n; ++i) {
        std::cin >> p[i];

        g[p[i]].emplace_back(i);
    }
    
    for (int i = 1; i <= n; ++i) {
        std::cin >> k[i];
    }

    int _t = 0;
    auto Dfs = [&](auto &&self, int v) -> void {
        tin[v] = ++_t;
        d[v] = d[p[v]] + 1;

        if (k[v]) {
            dep[d[v]].emplace(tin[v], k[v]);
        }

        for (auto to: g[v]) {
            self(self, to);
        }
        
        tout[v] = _t;
    };

    d[0] = -1;
    Dfs(Dfs, 1);

    int q; std::cin >> q;
    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int x, y; std::cin >> y >> x;

            if (dep[x].size() < dep[y].size()) {
                std::swap(dep[x], dep[y]);
            }
            
            while (dep[y].size()) {
                dep[x].emplace(*dep[y].begin());
                dep[y].erase(dep[y].begin());
            }
        } else if (type == 2) {
            int a, l; std::cin >> a >> l;

            dep[d[a]].emplace(tin[a], l);
        } else {
            int b; std::cin >> b;
            
            int val = 0;
            std::vector<std::pair<int, int>> del;
            if (dep[d[b]].size()) {
                for (auto it = dep[d[b]].lower_bound({tin[b], 0}); it != dep[d[b]].end(); ++it) {
                    auto [tn, vl] = *it;

                    if (tn > tout[b]) {
                        break;
                    }

                    del.emplace_back(tn, vl);

                    val += vl;
                }
            }

            for (auto [tn, vl]: del) {
                dep[d[b]].erase(dep[d[b]].find({tn, vl}));
            }

            if (val) {
                dep[d[b]].emplace(tin[b], val);
            }

            std::cout << val << '\n';
        }
    }

    return 0;
}
