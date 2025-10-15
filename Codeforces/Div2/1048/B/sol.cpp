/**
 *    author:  feev1x
 *    created: 08.09.2025 20:41:05
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<int64_t> a(n + 1), cnt(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        std::sort(a.begin() + 1, a.end(), std::greater<>());

        int64_t res = 0, sum = 0, pref = 0;
        for (int i = 1; i <= std::min(n, m + 1); ++i) {
            pref += a[i];

            res = std::max(res, pref * (m - i + 1) + sum);

            sum += pref;
        }

        std::cout << res << '\n';
    }
    return 0;
}
