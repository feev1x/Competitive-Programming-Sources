/**
 *    author:  feev1x
 *    created: 19.10.2025 17:09:49
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

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n = rnd(1, 8), k = rnd(1, 20); std::cout << n << ' ' << k << '\n';

    std::vector<int> p;
    for (int i = 1; i <= n; ++i)
        p.emplace_back(i);

    for (int i = 0; i < n; ++i) {
        int j = rnd(0, p.size() - 1);

        std::cout << p[j] << " \n"[i == n - 1];

        p.erase(p.begin() + j);
    }
    return 0;
}
