/**
 *    author:  feev1x
 *    created: 14.09.2025 18:16:57
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
    
    int n; std::cin >> n;

    int l = -1, r = -1;
    for (int i = 1; i <= n; ++i) {
        int u; std::cin >> u;

        if (u == 1)
            l = l == -1 ? i : l,
            r = i;
    }

    std::cout << r - l << '\n';
    return 0;
}
