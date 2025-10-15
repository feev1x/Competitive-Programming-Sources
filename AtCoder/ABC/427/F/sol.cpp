/**
 *    author:  feev1x
 *    created: 11.10.2025 18:34:52
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
    
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    if (n == 1) {
        std::cout << 1 + (a[1] == 0) << '\n';
        exit(0);
    }


    std::vector<std::map<int, int64_t>> dp0(n + 1), dp1(n + 1);

    dp1[1][a[1]]++;
    dp0[1][0]++;
    for (int i = 2; i <= n / 2; ++i) {
        for (auto [key, val]: dp0[i - 1]) {
            dp1[i][(key + a[i]) % m] += val;
            dp0[i][key] += val;
        }

        for (auto [key, val]: dp1[i - 1])
            dp0[i][key] += val;
    }

    dp1[n][a[n]]++;
    dp0[n][0]++;
    for (int i = n - 1; i > n / 2; --i) {
        for (auto [key, val]: dp0[i + 1]) {
            dp1[i][(key + a[i]) % m] += val;
            dp0[i][key] += val;
        }

        for (auto [key, val]: dp1[i + 1])
            dp0[i][key] += val;
    }

    int64_t res = 0;
    for (auto [key, val]: dp0[n / 2]) {
        res += val * dp1[n / 2 + 1][(m - key) % m];
        res += val * dp0[n / 2 + 1][(m - key) % m];
    }

    for (auto [key, val]: dp1[n / 2]) {
        res += val * dp0[n / 2 + 1][(m - key) % m];
    }

    std::cout << res << '\n';
    return 0;
}
