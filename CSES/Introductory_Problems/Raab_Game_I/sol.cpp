/**
 *    author:  feev1x
 *    created: 19.08.2025 15:19:10
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
        int n, a, b; std::cin >> n >> a >> b;

        int A = a, B = b;
        if (a + b > n || a + b > 0 && (a + b == a || a + b == b)) {
            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n";

        int st = n + 1 - a - b;
        std::vector<int> c1, c2;

        for (int i = 1; i < st; ++i) {
            c1.emplace_back(i);
            c2.emplace_back(i);
        }

        {
            int i = st + a - 1, j = n;
            while (a--) {
                c1.emplace_back(j--);
                c2.emplace_back(i--);
            }
        }

        int i = st + b - 1, j = n;
        while (b--) {
            c1.emplace_back(i--);
            c2.emplace_back(j--);
        }

        for (auto u: c1)
            std::cout << u << ' ';

        std::cout << '\n';
        for (auto u: c2)
            std::cout << u << ' ';

        std::cout << '\n';
    }

    return 0;
}
