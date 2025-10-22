/**
 *    author:  feev1x
 *    created: 17.10.2025 12:01:02
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

constexpr int N = 60;

using mat = std::array<std::array<std::array<int, 10>, 10>, 10>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; int a1, a2, a3; std::cin >> a1 >> a2 >> a3;    

    auto Comb = [&](mat &a, mat &b) {

    };
    return 0;
}
