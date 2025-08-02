/**
 *    author:  feev1x
 *    created: 31.07.2025 19:49:03
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
        
        std::vector<int64_t> s(n + 1), p(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> p[i];

        int64_t gcd = 0;
        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            std::cin >> s[i];

            gcd = std::gcd(gcd, std::lcm(s[i], p[i]));

            if (gcd != p[i])
                flag = false;
        }

        gcd = 0;
        for (int i = n; i >= 1; --i) {
            gcd = std::gcd(gcd, std::lcm(s[i], p[i]));

            if (gcd != s[i])
                flag = false;
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
