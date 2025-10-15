/**
 *    author:  feev1x
 *    created: 09.09.2025 21:36:19
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

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int64_t> l(n), r(n);
        std::vector<std::pair<int64_t, int64_t>> ar;

        int64_t res = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> l[i] >> r[i];

            ar.emplace_back(r[i] + l[i], l[i]);

            res -= l[i];

            res += r[i] - l[i];
        }

        if (n == 1) {
            std::cout << r[0] - l[0] << '\n';
            continue;
        }

        std::sort(ar.begin(), ar.end(), std::greater<>());

        int64_t mx = -ar[0].first + ar[0].second, mxx = 0;
        for (int i = 0; i < n / 2; ++i) {
            res += ar[i].first;

            mx = std::max(mx, -ar[i].first + ar[i].second);
        }

        for (int i = n / 2; i < ar.size(); ++i)
            mxx = std::max(mxx, ar[i].second);

        if (n & 1)
            res += std::max(mx + ar[n / 2].first, mxx);

        std::cout << res << '\n';
    }
    return 0;
}
