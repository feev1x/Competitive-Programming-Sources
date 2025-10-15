/**
 *    author:  feev1x
 *    created: 14.09.2025 18:13:25
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
    
    int x, c; std::cin >> x >> c;

    int mx = 0;
    for (int i = 0; i < x; ++i)
        if (i * c + i * 1000 <= x)
            mx = i;
        else
            break;

    std::cout << mx * 1000 << '\n';
    return 0;
}
