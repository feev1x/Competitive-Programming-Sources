/**
 *    author:  feev1x
 *    created: 09.09.2025 20:55:01
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

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int64_t> a(n + 1);

        int64_t res = 0, mx = (n & 1 ? n - 1 : n - 2);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            res += a[i] * (i & 1 ? 1 : -1);
        }

        int64_t mxx = -INF;
        for (int i = n; i >= 1; --i) {
            if (i & 1)
                mxx = std::max(mxx, -2 * a[i] + i);
            else
                mx = std::max(mx, mxx - i + 2 * a[i]);
        }

        mxx = -INF;
        for (int i = 1; i <= n; ++i) {
            if (i & 1)
                mxx = std::max(mxx, -2 * a[i] - i);
            else
                mx = std::max(mx, mxx + i + 2 * a[i]);
        }

        std::cout << res + mx << '\n';
    }
    return 0;
}
