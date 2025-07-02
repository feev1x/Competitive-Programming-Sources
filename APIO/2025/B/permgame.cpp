#include "permgame.h"
#include <bits/stdc++.h>

int Alice(int m, int e, std::vector<int> u, std::vector<int> v, int n, std::vector<int> p) {
    int cnt = 0;
    
    std::vector<int> pos(n), par(n, -1), nx(n, -1);
    for (int i = 0; i < n; ++i) {
        if (p[i] == i) {
            cnt++;
        }

        pos[p[i]] = i;
    }

    std::vector<std::vector<int>> g(m);
    for (int i = 0; i < e; ++i) {
        g[u[i]].emplace_back(v[i]);
        g[v[i]].emplace_back(u[i]);
    }

    for (int i = 0; i < m; ++i) {
        if (g[i].size() > 2) {
            return cnt;
        }
    }
    
    if (cnt > n - m) {
        return cnt;
    }

    int va = 0;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            va = i;

            break;
        }
    }

    auto Dfs = [&](auto &&self, int v) -> void {
        for (auto to: g[v]) {
            if (par[v] == to) {
                continue;
            }

            par[to] = v;
            nx[v] = to;

            self(self, to);
        }
    };

    Dfs(Dfs, va);


    auto Swap = [&](int i, int j) {
        std::swap(p[i], p[j]);
        std::swap(pos[p[i]], pos[p[j]]);
    };

    if (m == 2) {
        for (int i = 0; i < n; ++i) {
            if (i != p[i]) {
                Bob({i, pos[i]});
                Swap(i, pos[i]);
            }
        }

        return n;
    }

        
        while (true) {
            int ua = va;

            std::vector<int> t(m);
            std::vector<bool> used(n);
            for (int i = 0; i < n && ua != -1; ++i) {
                if (used[i] || i == p[i]) {
                    continue;
                }

                used[i] = true;
                t[ua] = i; 
                int j = pos[i];

                ua = nx[ua];
                while (ua != -1 && !used[j]) {
                    t[ua] = j;
                    used[j] = true;
                    j = pos[j];
                    ua = nx[ua];
                }
            }


            if (ua != -1) {
                break;
            }

            int idx = Bob(t);

            Swap(p[t[u[idx]]], p[t[v[idx]]]);
        }

        cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == i) {
                cnt++;
            }
        }

        return n - m + 1;
}
