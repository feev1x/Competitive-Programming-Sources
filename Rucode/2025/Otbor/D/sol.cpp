/**
 *    author:  feev1x
 *    created: 28.07.2025 21:45:01
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
    
    int64_t x, y, r; std::cin >> x >> y >> r;    

    int f1, f2, f3, f4, bl;

    f1 = f2 = f3 = f4 = bl = false;
    for (int64_t i = x - r; i <= x + r; ++i)
        for (int64_t j = y - r; j <= y + r; ++j) {
            if (std::abs(i - x) * std::abs(i - x) + std::abs(j - y) * std::abs(j - y) > r * r)
                continue;

            if (!i || !j) {
                bl = 1;
                continue;
            }

            if (i < 0 && j < 0)
                f1 = 1;
            else if (i < 0 && j > 0)
                f2 = 1;
            else if (i > 0 && j < 0)
                f3 = 1;
            else
                f4 = 1;
        }
            

    std::cout << (int)f1 + f2 + f3 + f4 + bl << '\n';
    return 0;
}
