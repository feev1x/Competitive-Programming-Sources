/**
 *    author:  feev1x
 *    created: 28.08.2025 20:48:13
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

    auto Ask = [&](char ch, int k) {
        std::cout << "? " << ch << ' ' << k << std::endl;

        int64_t got; std::cin >> got;
        return got;
    };
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        int64_t mx1 = -INF, mx2 = -INF;
        for (int i = 0; i < n; ++i) {
            int64_t x, y; std::cin >> x >> y;

            mx1 = std::max(mx1, x + y);
            mx2 = std::max(mx2, x - y);
        }

        Ask('U', 1e9);
        Ask('U', 1e9);
        Ask('R', 1e9);
        int64_t dist1 = Ask('R', 1e9);

        Ask('D', 1e9);
        Ask('D', 1e9);
        Ask('D', 1e9);
        int64_t dist2 = Ask('D', 1e9);

        int64_t sum1 = dist1 + mx1 - 4e9, sum2 = dist2 + mx2 - 4e9;

        std::cout << "! " << (sum1 + sum2) / 2 << ' ' << (sum1 - sum2) / 2 << std::endl;
    }
    return 0;
}
