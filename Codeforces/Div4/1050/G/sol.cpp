/**
 *    author:  feev1x
 *    created: 13.09.2025 20:40:13
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

constexpr int N = 2e5 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::vector<int>> div(N);
    for (int i = 2; i < N; ++i)
        for (int j = i; j < N; j += i)
            div[j].emplace_back(i);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> ans(n + 1), a(n + 1), cnt(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        int mx = 0, limcnt = 0;
        for (int i = 1; i <= n; ++i) {
            int new_limcnt = 0;

            for (auto u: div[a[i]]) {
                cnt[u]++;

                if (cnt[u] != i)
                    mx = std::max(mx, cnt[u]);
                else
                    new_limcnt++;
            }

            if (limcnt > new_limcnt)
                mx = i - 1;

            limcnt = new_limcnt;
            std::cout << mx << " \n"[i == n];
        }
    }
    return 0;
}
