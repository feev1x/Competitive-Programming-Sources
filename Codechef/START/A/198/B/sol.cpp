/**
 *    author:  feev1x
 *    created: 06.08.2025 20:49:45
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
        int n, m; std::cin >> n >> m;

        std::vector<int> a(n + 1), b(m + 1), p(m + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        for (int i = 1; i <= m; ++i) {
            std::cin >> b[i];

            p[i] = p[i - 1] + b[i];
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int l = i - cnt, r = std::min(i, m);

            int sum = p[r] - p[l - 1];

            if (r >= l && (sum != r - l + 1 && a[i] == 0 || sum != 0 && a[i] == 1))
                cnt++;
        }

        std::cout << n - cnt << '\n';
    }
    return 0;
}
