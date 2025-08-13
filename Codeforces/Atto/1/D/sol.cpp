/**
 *    author:  feev1x
 *    created: 12.08.2025 15:21:36
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

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<int> fac(n + 1, 1);
        std::vector<std::vector<int>> g(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        if (n - 1 != m) {
            std::cout << "0\n";
            continue;
        }

        for (int i = 2; i <= n; ++i)
            fac[i] = mul(fac[i - 1], i);

        int res = 4, cn = 0;
        for (int i = 1; i <= n; ++i) {
            int cnt = 0, cntt = 0;

            if (g[i].size() > 1)
                cn++;

            for (auto to: g[i])
                cnt += g[to].size() == 1,
                cntt += g[to].size() > 1;

            if (cntt > 2)
                res = 0;

            res = mul(res, fac[cnt]);
        }

        if (cn <= 1)
            res = mul(res, (MOD + 1) / 2);

        std::cout << res << '\n';
    }
    return 0;
}
