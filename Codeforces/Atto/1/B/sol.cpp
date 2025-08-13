/**
 *    author:  feev1x
 *    created: 12.08.2025 15:41:56
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
        int n, x; std::cin >> n >> x;
        
        std::string s; std::cin >> s;

        s = " " + s;

        int l = 0, r = n + 1;
        for (int i = x; i <= n; ++i)
            if (s[i] == '#') {
                r = i;
                break;
            }

        for (int i = x; i >= 1; --i)
            if (s[i] == '#') {
                l = i;
                break;
            }

        std::cout << std::max(std::min(n - r + 2, x), std::min(l + 1, n - x + 1)) << '\n';
    }
    return 0;
}
