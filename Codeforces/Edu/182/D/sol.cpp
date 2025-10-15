/**
 *    author:  feev1x
 *    created: 15.09.2025 21:32:31
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

constexpr int64_t N = 2e5 + 5;

int main() {
#define int int64_t
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, y; std::cin >> n >> y;

        std::vector<int> a(n), cnt(N), p(N);
        for (auto &u: a)
            std::cin >> u, cnt[u]++;

        for (int i = 1; i < N; ++i)
            p[i] = p[i - 1] + cnt[i];

        int64_t res = 0;
        for (int x = 2; x < N; ++x) {
            int64_t ans = -y * n;

            for (int l = 1; (l - 1) * x + 1 < N; ++l) {
                int64_t cn = p[std::min(l * x, N - 1)] - p[(l - 1) * x];

                ans += cn * l;

                ans += y * std::min(cnt[l], cn);
            }

            if (x == 2 || res < ans)
                res = ans;
        }

        std::cout << res << '\n';
    }
    return 0;
}
