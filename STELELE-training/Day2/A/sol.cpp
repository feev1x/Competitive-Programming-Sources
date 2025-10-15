/**
 *    author:  feev1x
 *    created: 13.10.2025 08:34:33
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

constexpr int N = 1e6 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> x[i];

    std::vector<int> cnt(N);
    cnt[0] = 1;
    while (q--) {
        int y; std::cin >> y;

        std::vector<int> suff(n + 2);

        int64_t res = 0;
        for (int i = n; i >= 1; --i) {
            suff[i] = (suff[i + 1] + x[i]) % y;

            res += cnt[suff[i]];

            cnt[suff[i]]++;
        }

        for (int i = 1; i <= n; ++i)
            cnt[suff[i]]--;

        std::cout << res << '\n';
    }
    return 0;
}
