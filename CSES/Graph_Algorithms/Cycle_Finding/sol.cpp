/**
 *    author:  feev1x
 *    created: 03.03.2025 18:41:27
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int64_t>>> g(n + 1);
    std::vector<std::array<int, 3>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        edges.push_back({u, v, w});
    }
    
    std::vector<int64_t> dis(n + 1, INF);
    std::vector<int> p(n + 1, -1), cnt(n + 1);
    std::vector<bool> in_queue(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::fill(dis.begin(), dis.end(), INF);
        std::fill(cnt.begin(), cnt.end(), 0);
        std::fill(p.begin(), p.end(), -1);
        std::fill(in_queue.begin(), in_queue.end(), false);
        
        dis[i] = 1;
        int cyc = -1;

        std::queue<int> q;

        q.emplace(i);
        in_queue[i] = true;
        while (q.size() && cyc == -1) {
            int v = q.front();

            in_queue[v] = false;
            q.pop();

            for (auto [to, w]: g[v]) {
                if (dis[to] > dis[v] + w) {
                    cnt[to]++;

                    if (cnt[to] > n) {
                        cyc = to;
                        p[to] = v;

                        break;
                    }

                    dis[to] = dis[v] + w;
                    p[to] = v;

                    if (!in_queue[to]) {
                        q.emplace(to);
                        in_queue[to] = true;
                    }
                }
            }
        }

        if (cyc == -1) {
            continue;
        }

        std::cout << "YES\n";

        for (int i = 0; i < n; ++i) {
            cyc = p[cyc];
            
            assert(cyc != -1);
        }

        std::vector<int> cycle;
        
        std::cout << cyc << ' ';

        auto Rec = [&](auto &&self, int v) {
            if (v == cyc) {
                return;
            }

            self(self, p[v]);

            std::cout << v << ' ';
        };

        Rec(Rec, p[cyc]);

        std::cout << cyc << '\n';

        exit(0);
    }

    std::cout << "NO\n";
    return 0;
}
