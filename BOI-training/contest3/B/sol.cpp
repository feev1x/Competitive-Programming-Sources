/**
 *    author:  feev1x
 *    created: 11.09.2025 17:04:35
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
    
    int64_t h, w, k; std::cin >> h >> w >> k;

    if (h * w % 3 != 0) {
        std::cout << "NO\n";
        exit(0);
    }

    if (h % 2 == 0 && w % 2 == 0 || h % 2 == 0 && w % 3 == 0 || w % 2 == 0 && h % 3 == 0 || (h - 2) % 3 == 0 || (w - 2) % 3 == 0 ) {
        std::cout << "YES\n";
        exit(0);
    }

    std::cout << "NO\n";
    return 0;
}
