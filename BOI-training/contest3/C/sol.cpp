/**
 *    author:  feev1x
 *    created: 11.09.2025 13:45:45
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

constexpr int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    if (m != n - 1) {
        std::cout << "NO\n";
        exit(0);
    }

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

//    std::vector<int> dp(1 << n, INF), next(1 << n);
//    std::vector<std::pair<int, int>> p(1 << n);
//
//    for (int mask = 0; mask < 1 << n; ++mask)
//        for (int i = 0; i < n; ++i) {
//            bool flag = false;
//
//            for (auto to: g[i + 1])
//                if (mask >> (to - 1) & 1)
//                    flag = true;
//
//            if (flag)
//                next[mask] |= (1 << i);
//        }
//
//    std::vector<std::vector<std::pair<int, int>>> adj(1 << n);
//    for (int mask = 0; mask < 1 << n; ++mask)
//        for (int i = 0; i < n; ++i)
//            if (mask >> i & 1) {
//                int new_mask = next[mask ^ (1 << i)];
//
//                adj[mask].emplace_back(new_mask, i);
//            }
//
//    std::queue<int> q;
//
//    dp[(1 << n) - 1] = 0;
//    q.emplace((1 << n) - 1);
//    while (q.size()) {
//        int v = q.front();
//
//        q.pop();
//        for (auto [to, i]: adj[v])
//            if (dp[to] > dp[v] + 1) {
//                dp[to] = dp[v] + 1;
//                p[to] = {v, i};
//                q.emplace(to);
//            }
//    }
//
//
//    int res = dp[0];
//    if (res == INF) {
//        std::cout << "NO\n";
//        exit(0);
//    }
//
//    std::vector<int> ans;
//    for (int nw = 0; nw != (1 << n) - 1; nw = p[nw].first)
//        ans.emplace_back(p[nw].second);
//
//    std::reverse(ans.begin(), ans.end());
//
//    assert(ans.size() == res);
//


    std::vector<int> ans;
    
    bool prev = 0;

    std::map<int, bool> mp;
    for (int nw = (1 << n) - 1; nw;) {
        if (mp[nw]) {
            std::cout << "NO\n";
            exit(0);
        }

        mp[nw] = true;
        std::vector<int> cnt(n + 1);

        for (int i = 1; i <= n; ++i) {
            int cn = 0, va = -1;

            for (auto to: g[i]) 
                if (nw >> (to - 1) & 1)
                    cn++, va = to;

            if (cn == 1)
                cnt[va]++;
        }

        int val = -1, cn = 0;
        for (int i = 1; i <= n; ++i)
            if (cnt[i] > cn)
                val = i, cn = cnt[i];

        if (val == -1) {
            if (prev) {
                std::cout << "NO\n";
                exit(0);
            }

            prev = true;
        }

        if (val == -1) val = 1;

        ans.emplace_back(val);

        val--;
        nw = (nw | (1 << val)) ^ (1 << val);

        int new_nw = 0;
        for (int i = 1; i <= n; ++i) {
            bool flag = false;

            for (auto to: g[i])
                if (nw >> (to - 1) & 1)
                    flag = true;

            if (flag)
                new_nw |= (1 << i - 1);
        }

        nw = new_nw;
    }

    std::cout << "YES\n" << ans.size() << '\n';
    for (auto u: ans)
        std::cout << u + 1 << ' ';

    std::cout << '\n';
    return 0;
}

