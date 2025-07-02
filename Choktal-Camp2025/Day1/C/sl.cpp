/**
 *    author:  feev1x
 *    created: 01.07.2025 09:52:05
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<std::vector<std::pair<int, int>>> g(n + 1), adj(n + 1);
        std::vector<std::array<int, 3>> e;
        for (int i = 0; i < m; ++i) {
            int u, v, w; std::cin >> u >> v >> w;

            e.push_back({u, v, w});
            g[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int a, b; std::cin >> a >> b;

        bool flag = true;
        std::vector<bool> used(n + 1), can(n + 1), cyc(n + 1), ins(n + 1), FA(n + 1), TB(n + 1), FA0(n + 1), TB0(n + 1), la(n + 1), lb(n + 1);
        std::vector<int> xr(n + 1), pr(n + 1), par(n + 1), vl(n + 1), gt(n + 1), tin(n + 1);


        std::vector<bool> tb(n + 1), fa(n + 1);
        int nw = 0;
        {
            std::queue<int> q;

            q.emplace(a);
            used[a] = true;
            fa[a] = 1;

            while (q.size()) {
                int v = q.front();

                q.pop();

                for (auto [to, w]: g[v]) {
                    if (!used[to]) {
                        gt[to] = nw ^ w;
                        q.emplace(to);
                        used[to] = true;
                    }

                    if (gt[to] != w ^ nw) {
                        la[to] = true;
                    }

                    if (la[v]) {
                        la[to] = true;
                    }

                    if (la[to] || (nw ^ w)) {
                        FA[to] = FA0[to] = true;
                    } else {
                        FA0[to] = true;
                    }

                    fa[to] = fa[to] ^ fa[v];
                }
            }
        }

        nw = 0;
        std::fill(used.begin(), used.end(), false);
        {
            std::queue<int> q;

            q.emplace(b);
            used[b] = true;
            tb[b] = 1;

            while (q.size()) {
                int v = q.front();

                q.pop();

                for (auto [to, w]: adj[v]) {
                    if (!used[to]) {
                        gt[to] = nw ^ w;
                        q.emplace(to);
                        used[to] = true;
                    }

                    if (gt[to] != w ^ nw) {
                        lb[to] = true;
                    }

                    if (lb[v]) {
                        lb[to] = true;
                    }

                    if (lb[to] || (nw ^ w)) {
                        TB[to] = TB0[to] = true;
                    } else {
                        TB0[to] = true;
                    }

                    tb[to] = tb[to] ^ tb[v];
                }
            }
        }

        int _t = 1;
        std::fill(used.begin(), used.end(), false);
        auto Cyc = [&](auto &&self, int v, int ifa, int itb, int ifa0, int  itb0) -> void {
            used[v] = true;
            ins[v] = true;
            tin[v] = _t++;

            if (v == b) {
                can[v] = true;
            }

            for (auto [to, w]: g[v]) {
                if (used[to]) {
                    if (ins[to]) {
                        if (tin[itb0] >= tin[to]) {
                            if (tin[ifa] >= tin[to] && (!ins[a] || tin[a] < tin[to]) || (xr[v] ^ xr[to] ^ w) || tin[itb] >= tin[to] && (!ins[b] || tin[b] < tin[to])) {
                                flag = false;

                                return;
                            }
                        }
                    }

                    continue;
                }

                par[to] = v;
                xr[to] = xr[v] ^ w;
                self(self, to, FA[to] ? to : ifa, TB[to] ? to : itb, FA0[to] ? to : ifa0, TB0[to] ? to : itb0);
                if (!flag) {
                    return;
                }

                if (can[to]) {
                    can[v] = true;
                }
            }

            ins[v] = false;
        };

//        Cyc(Cyc, a, FA[a] ? a : 0, TB[a] ? a : 0, FA0[a] ? a : 0, TB0[a] ? a : 0);
//
//        if (!FA0[b]) {
//            std::cout << -1 << '\n';
//
//            continue;
//        }


        int res = 0;
        for (auto [u, v, w]: e) {
            res = res ^ (w * (fa[u] & tb[v]));
        }

        std::cout << res << '\n';
    }
    return 0;
}
