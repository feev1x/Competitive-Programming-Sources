/**
 *    author:  feev1x
 *    created: 17.09.2025 20:40:01
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

        std::vector<int> a(n + 1), b(k + 1);

        int64_t res = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], res += a[i];

        std::sort(a.begin() + 1, a.end(), std::greater<>());
        for (int i = 1; i <= k; ++i)
            std::cin >> b[i];

        std::sort(b.begin() + 1, b.end());
        int sum = 0, nw = 1;
        for (int i = 1; i <= k && sum + b[i] <= n; ++i) {
            sum += b[i];

            res -= a[nw + b[i] - 1];

            nw += b[i];
        }

        std::cout << res << '\n';
    }
    return 0;
}
