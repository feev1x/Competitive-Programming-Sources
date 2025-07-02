#include "stub.h"

int solve(int n, std::vector<int> p){
    std::vector<bool> bad(n + 1);
    std::vector<int> sz(n + 1);
    std::vector<std::vector<int>> g(n + 1);

    p.emplace(p.begin(), 0);
    p.emplace(p.begin(), 0);

    for (int i = 2; i <= n; ++i) {
        g[i].emplace_back(p[i]);
        g[p[i]].emplace_back(i);
    }

    auto Dfs = [&](auto &&self, int v) -> void {
        if (bad[v]) {
            sz[v] = 0;

            return;
        }

        sz[v] = 1;
        
        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            self(self, to);

            sz[v] += sz[to];
        }
    };

    Dfs(Dfs, 1);

    int x = -1, dif = 2e9;
    auto Find = [&](auto &&self, int v) -> void {
        if (bad[v]) {
            return;
        }

        if (dif > std::abs(n - 2 * sz[v])) {
            x = v;
            dif = std::abs(n - 2 * sz[v]);
        }

        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            self(self, to);
        }
    };

    int rt = 1;
    for (int i = 1; i <= 35; ++i) {
        dif = 2e9, x = -1;
        Find(Find, rt);

        std::cerr << x << ' ' << dif << '\n';
        bool flag = ask(x);

        if (!flag) {
            bad[x] = true;
        } else {
            rt = x;
        }

        Dfs(Dfs, rt);
        
        n = sz[rt];
    }

    return rt;
}
