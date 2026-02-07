/**
 *    author:  feev1x
 *    created: 30.10.2025 10:09:20
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

constexpr int N = 2e6 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1), idx(N), p(n + 1), id(n + 1), dp(n + 1, 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], idx[a[i]] = i, id[i] = i;

    for (int i = 2; i < N; ++i) {
        int old = -1;

        for (int j = i; j < N; j += i)
            if (idx[j]) {
                if (old != -1)
                    g[idx[j]].emplace_back(old);

                old = idx[j];
            }
    }

    std::sort(id.begin() + 1, id.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    for (int i = 1; i <= n; ++i) {
        int j = id[i];

        for (auto to: g[j]) {
            if (dp[j] < dp[to] + 1) {
                dp[j] = dp[to] + 1;
                p[j] = to;
            }
        }
    }

    int mx = 0, sz = 0;
    for (int i = 1; i <= n; ++i)
        if (sz < dp[i])
            sz = dp[i], mx = i;

    std::cout << sz << '\n';

    std::vector<int> res;

    int u = mx;
    while (p[u])
        res.emplace_back(u), u = p[u];

    res.emplace_back(u);

    std::reverse(res.begin(), res.end());
    for (auto u: res)
        std::cout << u << ' ';

    return 0;
}
