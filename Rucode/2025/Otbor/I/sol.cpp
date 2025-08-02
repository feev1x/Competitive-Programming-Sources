/**
 *    author:  feev1x
 *    created: 28.07.2025 23:16:43
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
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    int64_t res = n + 2;
    for (int bt = 0; bt < 61; ++bt) {
        int64_t ans = 0, xr = 0;

        bool flag = false;
        for (int i = 1; ans < res && i <= n; ++i) {
            int64_t add = res + 5;

            int cn = 0;
            for (int64_t x = 0; ans + x < res; ++x) {
                int64_t val = a[i] + x, val1 = std::max((int64_t)0, a[i] - x);

                if (val >> bt & 1) {
                    add = x;
                    cn++;
                }

                if (val1 >> bt & 1) {
                    add = -x;
                    cn++;
                }

                if (cn)
                    break;
            }

            if (cn == 2 && add != 0)
                flag = true;

            ans += std::abs(add);

            xr ^= (a[i] + add);
        }
        
        if (xr == 0 && !flag)
            ans += (bt == 0 ? 2 : 1);

        res = std::min(res, ans);
    }

    std::cout << res << '\n';
    return 0;
}
