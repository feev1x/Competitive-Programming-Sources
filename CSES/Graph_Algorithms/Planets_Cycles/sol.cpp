/**
 *    author:  feev1x
 *    created: 04.03.2025 01:30:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<bool> used(n + 1), cyc(n + 1);
    std::vector<int> p(n + 1), sz(n + 1), head(n + 1), dis(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        g[p[i]].emplace_back(i);
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
        
        for (int v = p[u]; ; v = p[v]) {
            cyc[v] = true;
            head[v] = v;
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

    for (int i = 1; i <= n; ++i) {
        std::cout << dis[i] + sz[head[i]] << " \n"[i == n];
    }

    return 0;
}
