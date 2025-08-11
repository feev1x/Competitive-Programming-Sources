/**
 *    author:  feev1x
 *    created: 10.08.2025 20:46:28
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
        int n, k; std::cin >> n >> k;

        std::vector<int> s(n), t(n);
        for (auto &u: s) {
            std::cin >> u;

            u = std::min(k - (u % k), u % k);
        }

        for (auto &u: t) {
            std::cin >> u;

            u = std::min(k - (u % k), u % k);
        }

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        std::cout << (s == t ? "YES\n" : "NO\n");
    }
    return 0;
}
