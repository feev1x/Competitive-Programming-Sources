/**
 *    author:  feev1x
 *    created: 02.08.2025 12:06:53
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
    
    int64_t x, y; std::cin >> x >> y;

    int64_t l = 1, r = 3e9, ans = -1;
    while (l <= r) {
        int64_t m = l + r >> 1;

        if (m * m - m <= y * 2)
            l = m + 1, ans = m;
        else
            r = m - 1;
    }

    std::cout << std::min(x, ans) << '\n';
    return 0;
}
