/**
 *    author:  feev1x
 *    created: 20.09.2025 20:39:35
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

        if (n == 1) {
            std::cout << "1 1\n";
            continue;
        }
        
        if (n & 1) {
            std::cout << 1 << ' ';

            for (int i = n; i > 1; i -= 2)
                std::cout << i << ' ';

            std::cout << "1 " << n - 1 << ' ';

            for (int i = 3; i <= n; i += 2)
                std::cout << i << ' ';

            for (int i = n - 3; i > 1; i -= 2)
                std::cout << i << ' ';

            std::cout << n - 1 << ' ';
            for (int i = 2; i < n - 1; i += 2)
                std::cout << i << ' ';
        } else {
            std::cout << 1 << ' ';

            for (int i = n - 1; i > 1; i -= 2)
                std::cout << i << ' ';

            std::cout << n << " 1 ";

            for (int i = 3; i < n; i += 2)
                std::cout << i << ' ';

            for (int i = n - 2; i > 1; i -= 2)
                std::cout << i << ' ';

            std::cout << n << ' ';
            for (int i = 2; i < n; i += 2)
                std::cout << i << ' ';
        }
        
        std::cout << '\n';
    }
    return 0;
}
