/**
 *    author:  feev1x
 *    created: 04.09.2025 14:32:37
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

constexpr int N = 1e5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;
    while (tt--) {
        std::cout << "? " << N;

        for (int i = 0; i < N; ++i)
            std::cout << " 1";

        std::cout << std::endl;

        int x; std::cin >> x;

        if (x == 1) {
            std::cout << "! " << N << std::endl;
            continue;
        }

        int l = (N + x - 1) / x, r = (N + x - 2) / (x - 1) - 1;

        if (r == l) {
            std::cout << "! " << l << std::endl;
            continue;
        }

        int sz = (r - l) * 2;

        std::cout << "? " << sz;
        for (int i = 1; i <= r - l; ++i)
            std::cout << ' ' << l << ' ' << i;

        std::cout << std::endl;
        std::cin >> x;

        std::cout << "! " << l + sz - x << std::endl;
    }
    return 0;
}
