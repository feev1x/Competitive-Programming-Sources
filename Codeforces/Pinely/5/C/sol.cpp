/**
 *    author:  feev1x
 *    created: 30.10.2025 23:04:19
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

        std::vector<int> a(n);
        for (auto &u: a)
            std::cin >> u;

        std::sort(a.begin(), a.end());

        int l = 0, r = n - 1, sum = 0;

        int64_t res = 0;
        std::vector<int> ans;
        while (l <= r) {
            if (sum + a[r] >= x) {
                sum = (sum + a[r]) - x;
                res += a[r];

                ans.emplace_back(a[r--]);
            } else {
                sum += a[l];

                ans.emplace_back(a[l++]);
            }
        }

        std::cout << res << '\n';
        for (auto u: ans)
            std::cout << u << ' ';

        std::cout << '\n';
    }
    return 0;
}
