/**
 *    author:  feev1x
 *    created: 10.08.2025 20:37:37
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
        int n; std::cin >> n;

        std::vector<int> a(n), b(n);
        for (auto &u: a)
            std::cin >> u;

        int sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> b[i];

            if (a[i] > b[i])
                sum += a[i] - b[i];
        }

        std::cout << sum + 1 << '\n';
    }
    return 0;
}
