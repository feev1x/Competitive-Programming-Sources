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

        std::vector<bool> used(n + 1), cyc(n + 1), ins(n + 1), da(n + 1), db(n + 1);
        std::vector<std::vector<std::pair<int, int>>> g(n + 1), adj(n + 1);
        std::vector<std::array<int, 3>> e;
        for (int i = 1; i <= m; ++i) {
            int u, v, w; std::cin >> u >> v >> w;

            if (u == v) {
                cyc[u] = true;
            }

            e.push_back({u, v, w});
            g[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int a, b; std::cin >> a >> b;

        bool flag = true;
        std::vector<int> gt(n + 1, -1), tin(n + 1), low(n + 1), gt1(n + 1, -1);

        int _t = 1;
        std::stack<int> stk;
        auto Tj = [&](auto &&self, int v) -> void {
            tin[v] = low[v] = _t++;
            ins[v] = true;

            stk.emplace(v);

            for (auto [to, w]: g[v]) {
                if (!tin[to]) {
                    self(self, to);

                    low[v] = std::min(low[v], low[to]);
                } else if (ins[to]) {
                    low[v] = std::min(low[v], tin[to]);
                }
            }

            if (low[v] == tin[v]) {
                int x;

                if (stk.top() == v) {
                    ins[v] = false;

                    stk.pop();
                } else {
                    do {
                        x = stk.top(), cyc[x] = true, ins[x] = false;
                        stk.pop();
                    } while (x != v);
                }
            }
        };

        for (int i = 1; i <= n; ++i) {
            if (!tin[i]) {
                Tj(Tj, i);
            }
        }

        {
            std::queue<int> q;

            q.emplace(a);
            used[a] = true;
            gt[a] = 0;

            while (q.size()) {
                int v = q.front();

                q.pop();
                for (auto [to, w]: g[v]) {
                    if (!used[to]) {
                        gt[to] = gt[v] ^ w;
                        q.emplace(to);
                        used[to] = true;
                    }

                    if (gt[to] != (gt[v] ^ w) || da[v]) {
                        if (!da[to]) {
                            q.emplace(to);
                        }

                        da[to] = true;
                    }
                }
            }
        }

        std::fill(used.begin(), used.end(), false);
        {
            std::queue<int> q;

            q.emplace(b);
            used[b] = true;
            gt1[b] = 0;

            while (q.size()) {
                int v = q.front();

                q.pop();
                for (auto [to, w]: adj[v]) {
                    if (!used[to]) {
                        gt1[to] = gt1[v] ^ w;
                        q.emplace(to);
                        used[to] = true;
                    }

                    if (gt1[to] != (gt1[v] ^ w) || db[v]) {
                        if (!db[to]) {
                            q.emplace(to);
                        }

                        db[to] = true;
                    }
                }
            }
        }

        bool found = false;
        for (int i = 1; i <= n; ++i) {
            if (!cyc[i] || gt[i] == -1 || gt1[i] == -1) {
                continue;
            }

            if (da[i] || db[i] || gt[i] != gt1[i]) {
                found = true;

                break;
            }
        }

        if (found) {
            std::cout << "-1\n";

            continue;
        }

        std::vector<bool> tb(n + 1), fa(n + 1);
        fa[a] = 1;
        tb[b] = 1;
        int nw = 0;
        std::fill(used.begin(), used.end(), false);
        auto Dfs = [&](auto &&self, int v) -> void {
            used[v] = true;

            if (v == b) {
                return;
            }

            for (auto [to, w]: g[v]) {
                if (!used[to] && !cyc[to]) {
                    self(self, to);
                }

                tb[v] = tb[v] ^ tb[to];
            }
        };

        Dfs(Dfs, a);
        nw = 0;
        std::fill(used.begin(), used.end(), false);
        auto Dfs1 = [&](auto &&self, int v) -> void {
            used[v] = true;

            if (v == a) {
                return;
            }

            for (auto [to, w]: adj[v]) {
                if (!used[to] && !cyc[to]) {
                    self(self, to);
                }

                fa[v] = fa[v] ^ fa[to];
            }
        };

        Dfs1(Dfs1, b);

        int res = 0;
        for (auto [u, v, w]: e) {
            res = res ^ (w * (fa[u] & tb[v]));
        }

        std::cout << res << '\n';
    }
    return 0;
}
