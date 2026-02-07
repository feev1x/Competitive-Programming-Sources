/**
 *    author:  feev1x
 *    created: 30.10.2025 22:36:19
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
        int r0, x, d, n; std::cin >> r0 >> x >> d >> n;

        std::string s; std::cin >> s;

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
                r0 -= d, cnt++;
            else if (s[i] == '2' && r0 < x)
                cnt++;
        }

        std::cout << cnt << '\n';
    }
    return 0;
}
