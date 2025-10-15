/**
 *    author:  feev1x
 *    created: 10.10.2025 11:11:11
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::unordered_map<int, int, custom_hash>> sol(n + 1);
    std::vector<int> k(n + 1), col(n + 1, -1), cnt(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> k[i];

        for (int j = 0; j < k[i]; ++j) {
            int u; std::cin >> u;

            g[i].emplace_back(u);
            sol[i][u]++;

            if (sol[i][u] == 1)
                adj[u].emplace_back(i);
        }
    }

    std::queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (g[i].size() == 1)
            col[i] = 0;

    for (int i = 1; i <= n; ++i) {
        int ci = 0;

        for (auto to: g[i]) {
            cnt[i] += col[to] == -1;

            if (to == i)
                ci++;
        }

        if (ci > 1)
            cnt[i] = 1e9;
    }

    std::vector<bool> used(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] <= 1 && col[i])
            q.emplace(i), used[i] = true;
    }

    auto ug = g;

    for (int i = 1; i <= n; ++i) {
        std::sort(ug[i].begin(), ug[i].end());

        ug[i].erase(unique(ug[i].begin(), ug[i].end()), ug[i].end());
    }

    while (q.size()) {
        int v = q.front();

        q.pop();

        int cn = 0, mx = -1, mx2 = -1;
        for (auto to: ug[v])
            if (col[to] == -1)
                cn++;
            else if (mx < col[to])
                mx2 = mx, mx = col[to];
            else if (mx2 < col[to])
                mx2 = col[to];

        if (cn)
            col[v] = mx + 1;
        else
            col[v] = mx2 + 1;

        for (auto to: adj[v]) {
            if (to == v)
                continue;

            cnt[to] -= sol[to][v];
            if ((col[to] == -1 || cnt[to] == 0) && cnt[to] <= 1 && !used[to])
                q.emplace(to), used[to] = true;
        }
    }

    std::cout << col[1] << '\n';
    return 0;
}
