/**
 *    author:  feev1x
 *    created: 08.09.2025 22:18:42
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

constexpr int N = 2e5 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<bool> lv(n + 1, true);
        std::vector<int> p(n + 1), d(n + 1), cnt(n + 1);
        for (int i = 2; i <= n; ++i)
            std::cin >> p[i];

        d[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int u = p[i];

            std::vector<int> pr;
            while (d[u] == 0) {
                pr.emplace_back(u);

                u = p[u];
            }

            lv[u] = false;

            std::reverse(pr.begin(), pr.end());
            for (auto v: pr) {
                lv[v] = false;
                d[v] = d[p[v]] + 1;
            }

            d[i] = d[p[i]] + 1;

            cnt[d[i]]++;
        }

        int mn = n;

        for (int i = 1; i <= n; ++i)
            if (lv[i])
                mn = std::min(mn, d[i]);

        bool flag = true;
        
        std::bitset<N> dp;

        int sum = 0;

        dp[0] = true;
        for (int i = 1; i <= mn; ++i) {
            sum += cnt[i];

            dp = dp | (dp << cnt[i]);
        }

        auto fp = dp;
        for (int i = 1; i <= n - sum; ++i) {
            auto new_dp = dp;
            new_dp = new_dp | (dp << i);

            fp = fp | new_dp;
        }

        if (fp[k] || fp[n - k])
            flag = false;

        std::cout << mn - flag << '\n';
    }
    return 0;
}
