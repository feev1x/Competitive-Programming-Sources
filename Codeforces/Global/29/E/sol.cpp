/**
 *    author:  feev1x
 *    created: 20.09.2025 23:04:18
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

constexpr int N = 31;

int main() {
#define int int64_t
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, q; std::cin >> n >> q;

        std::vector<int> a(n + 1);

        int a_or = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], a_or |= a[i];

        std::vector<int> ans(N);
        for (int i = 0; i < N; ++i) {
            std::vector<bool> used(n + 1);

            for (int j = i; j >= 0; --j) {
                int mx = 0, pos = 0;

                for (int k = 1; k <= n; ++k) {
                    if (used[k])
                        continue;

                    if (a[k] >> j & 1) {
                        mx = 1 << j;
                        pos = 0;

                        break;
                    }

                    if (mx < (a[k] % (1 << j)))
                        mx = (a[k] % (1 << j)), pos = k;
                }

                used[pos] = true;

                ans[i] += 1 << j;
                ans[i] -= mx;
            }
        }

        while (q--) {
            int b; std::cin >> b;

            int mx = -1;
            for (int i = N - 1; i >= 0; --i)
                if (ans[i] <= b) {
                    mx = i;
                    break;
                }

            int res = mx + 1;
            for (int i = mx + 1; i < N; ++i)
                res += a_or >> i & 1;

            std::cout << res << '\n';
        }
    }
    return 0;
}
