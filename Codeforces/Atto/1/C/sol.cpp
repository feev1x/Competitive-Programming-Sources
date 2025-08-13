/**
 *    author:  feev1x
 *    created: 12.08.2025 14:56:35
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

        std::vector<int64_t> a(n), b(n);
        for (auto &u: a)
            std::cin >> u;

        for (auto &u: b)
            std::cin >> u;

        int64_t res = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > b[i])
                std::swap(a[i], b[i]);

            res += b[i] - a[i];
        }

        std::vector<int> idx(n);

        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int i, int j) {
            return a[i] < a[j];
        });

        int64_t mn = 1e18, mx = 0;
        for (auto i: idx) {
            int64_t l = a[i], r = b[i];

            if (mx >= l) {
                mn = 0;
                break;
            }

            if (mx)
                mn = std::min(mn, (l - mx) * 2);

            mx = std::max(mx, r);
        }

        std::cout << res + mn << '\n';
    }
    return 0;
}
