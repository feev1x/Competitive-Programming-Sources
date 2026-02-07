#include <bits/stdc++.h>

int T;

inline void solve() {
    int n; std::cin >> n;

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<int> par(n + 1), nx(n + 1), pv(n + 1), dep(n + 1), tin(n + 1);
    std::vector<std::set<int>> use(n + 5), shi(n + 5);
    std::vector<std::vector<int>> calc(n + 5);

    int _t = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = ++_t;
        par[v] = p;
        dep[v] = dep[p] + 1;
        use[dep[v]].emplace(v);
        calc[dep[v]].emplace_back(v);

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }
    };

    Dfs(Dfs, 1, 1);

    for (int dp = 2; dp < n + 5; ++dp) {
        if (use[dp].empty()) {
            continue;
        }

        std::set<std::pair<int, int>> bc, unc, did;
        for (auto u: calc[dp]) {
            if (!nx[par[u]]) {
                if (bc.size() && par[bc.begin()->second] != par[u]) {
                    int v = bc.begin()->second;

                    bc.erase(bc.begin());
                    unc.erase({tin[par[u]], par[u]});
                    did.emplace(tin[v], v);
                    nx[par[u]] = v;
                    pv[v] = par[u];
                } else if (did.size() && par[did.begin()->second] != par[u]) {
                    int v = did.begin()->second;

                    unc.erase({tin[par[u]], par[u]});
                    did.emplace(tin[u], u);
                    nx[pv[v]] = u;
                    pv[u] = pv[v];
                    nx[par[u]] = v;
                    pv[v] = par[u];

                    continue;
                } else {
                    unc.emplace(tin[par[u]], par[u]);
                }
            }

            if (unc.size() && unc.begin()->second != par[u]) {
                int v = unc.begin()->second;

                unc.erase(unc.begin());
                did.emplace(tin[u], u);
                nx[v] = u;
                pv[u] = v;
            } else {
                bc.emplace(tin[u], u);
            }
        }

        for (auto u: calc[dp - 1]) {
            if (g[u].size() == 1 && u != 1 && bc.size()) {
                int v = bc.begin()->second;

                bc.erase(bc.begin());
                nx[u] = v;
                pv[v] = u;
            }
        }

        for (auto [u, v]: bc) {
            shi[dp].emplace(v);
        }
    }

    shi[1].emplace(1);

    int res = 0, left = n;

    std::vector<std::vector<int>> ans;
    std::set<int> hv;
    for (int i = 1; i < n + 5; ++i) {
        if (shi[i].size()) {
            hv.emplace(i);
        }
    }

    while (left) {
        int ls = 0;
        dep[0] = -1;

        ans.resize(res + 1);
        while (hv.size() && *hv.rbegin() > dep[ls] + 1) {
            int nd = *hv.upper_bound(dep[ls] + 1);

            int v = *shi[nd].begin();

            shi[nd].erase(shi[nd].begin());
            if (shi[nd].empty()) {
                hv.erase(nd);
            }

            while (nx[v]) {
                left--;

                ans.back().emplace_back(v);
                v = nx[v];
            }

            ans.back().emplace_back(v);
            left--;
            ls = v;
        }

        res++;
    }

    std::cout << res << '\n';

    for (auto u: ans) {
        std::cout << u.size() << '\n';

        for (auto v: u) {
            std::cout << v << ' ';
        }

        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        T = tt;
        solve();
    }

    return 0;
}
