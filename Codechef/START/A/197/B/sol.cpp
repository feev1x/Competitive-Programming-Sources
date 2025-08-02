/**
 *    author:  feev1x
 *    created: 30.07.2025 20:34:35
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

        std::string s; std::cin >> s;

        s = " " + s;

        int l = 1, r = n, ans = 1;
        while (l <= r) {
            int m = l + r >> 1;

            bool flag = false;
            int nw = 1, ls0 = 0, ls1 = 0;

            for (int i = 1; i <= n; ++i) {
                if (s[i] == '1')
                    ls1 = std::max(ls0 + 1, ls1 + 1);
                else
                    ls0++;
                
                if (ls1 >= m || ls0 >= m)
                    nw++, ls1 = ls0 = 0;
            }

            if (nw > k)
                l = m + 1, ans = m;
            else
                r = m - 1;
        }

        std::cout << ans << '\n';
    }
    return 0;
}
