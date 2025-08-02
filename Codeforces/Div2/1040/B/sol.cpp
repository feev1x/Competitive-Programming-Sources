/**
 *    author:  feev1x
 *    created: 31.07.2025 20:40:29
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
        int n, s; std::cin >> n >> s;

        std::vector<int> a(n), cnt(3);
        for (auto &u: a)
            std::cin >> u, s -= u, cnt[u]++;

        if (s < 0 || s == 1) {
            while (cnt[0]--)
                std::cout << "0 ";

            while (cnt[2]--)
                std::cout << "2 ";

            while (cnt[1]--)
                std::cout << "1 ";

            std::cout << '\n';
        } else
            std::cout << "-1\n";
    }
    return 0;
}
