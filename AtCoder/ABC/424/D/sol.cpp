/**
 *    author:  feev1x
 *    created: 20.09.2025 18:29:12
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;
        
        std::vector<std::string> s(n);
        for (auto &u: s)
            std::cin >> u;

        std::vector dp(m, std::vector<int>(1 << n, INF));
        for (int mask = 0; mask < 1 << n; ++mask) {
            int cost = 0;
            
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1) {
                    if (s[i][0] == '.') {
                        cost = INF;
                        continue;
                    }
                } else {
                    if (s[i][0] == '#')
                        cost++;
                }
            }

            dp[0][mask] = cost;
        }

        for (int j = 1; j < m; ++j) {
            for (int mask = 0; mask < 1 << n; ++mask) {
                int cost = 0;
                
                for (int i = 0; i < n; ++i) {
                    if (mask >> i & 1) {
                        if (s[i][j] == '.') {
                            cost = INF;
                            continue;
                        }
                    } else {
                        if (s[i][j] == '#')
                            cost++;
                    }
                }

                if (cost == INF)
                    continue;

                for (int mask1 = 0; mask1 < 1 << n; ++mask1) {
                    if (dp[j - 1][mask1] == INF)
                        continue;

                    bool flag = true;
                    for (int i = 0; i + 1 < n; ++i) {
                        int cnt = (mask >> i & 1) + (mask >> (i + 1) & 1);

                        cnt += (mask1 >> i & 1) + (mask1 >> (i + 1) & 1);

                        if (cnt == 4) {
                            flag = false;
                            break;
                        }
                    }

                    if (flag)
                        dp[j][mask] = std::min(dp[j][mask], dp[j - 1][mask1] + cost);
                }
            }
        }

        std::cout << *std::min_element(dp.back().begin(), dp.back().end()) << '\n';
    }
    return 0;
}
