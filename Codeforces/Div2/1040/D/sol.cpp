/**
 *    author:  feev1x
 *    created: 31.07.2025 21:09:47
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

        std::vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> p[i];

        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int j = 1; j < i; ++j)
                cnt += p[j] > p[i];

            for (int j = i + 1; j <= n; ++j)
                cnt += p[i] > p[j];

            p[i] = 2 * n - p[i];

            int cnt1 = 0;
            for (int j = 1; j < i; ++j)
                cnt1 += p[j] > p[i];

            for (int j = i + 1; j <= n; ++j)
                cnt1 += p[i] > p[j];

            if (cnt <= cnt1)
                p[i] = 2 * n - p[i];
        }

        int res = 0;
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                res += p[i] > p[j];

        std::cout << res << '\n';
    }
    return 0;
}
