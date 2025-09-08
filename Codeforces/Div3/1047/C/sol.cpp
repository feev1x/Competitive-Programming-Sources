/**
 *    author:  feev1x
 *    created: 07.09.2025 20:42:09
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
        int64_t a, b; std::cin >> a >> b;

        int64_t res = ((a + b) & 1 ? int64_t(0) : a + b);

        if ((a & 1) & (b & 1)) {
            res = std::max(res, a * b + 1);
        }
        
        if (a % 2 == 0 && b % 2 == 0) {
            res = std::max(res, a * (b / 2) + 2);
        }

        if (a % 2 == 1 && b % 2 == 0) {
            if (b % 4 != 0) {
                std::cout << "-1\n";
                continue;
            }

            res = std::max(res, a * (b / 2) + 2);
        }

        if (a % 2 == 0 && b % 2 == 1) {
            std::cout << "-1\n";
            continue;
        }

        std::cout << res << '\n';
    }
    return 0;
}
