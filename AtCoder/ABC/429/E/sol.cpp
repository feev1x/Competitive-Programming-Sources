/**
 *    author:  feev1x
 *    created: 25.10.2025 18:34:47
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> val(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::string s; std::cin >> s;

    s = " " + s;

    std::queue<std::pair<int, int>> q;
    std::vector<std::array<int, 2>> d(n + 1, {INF, INF});
    for (int i = 1; i <= n; ++i)
        if (s[i] == 'S')
            q.emplace(i, 0), d[i][0] = 0, val[i] = i;

    while (q.size()) {
        auto [v, tp] = q.front();

        q.pop();
        for (auto to: g[v]) {
            if (d[to][tp] == INF) {
                d[to][tp] = d[v][tp] + 1;

                if (!tp)
                    val[to] = val[v];

                q.emplace(to, tp);
            } else if (!tp && d[to][1] == INF && val[v] != val[to]) {
                d[to][1] = d[v][0] + 1;

                q.emplace(to, 1);
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        if (s[i] == 'D')
            std::cout << d[i][0] + d[i][1] << '\n';

    return 0;
}
