/**
 *    author:  feev1x
 *    created: 18.10.2025 13:26:09
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

constexpr int N = 5e3 + 5;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::array<std::vector<std::vector<int64_t>>, 4> a{};
    for (int i = 0; i < n; ++i) {
        int type; std::cin >> type; type--;

        if (type == 0) {
            int64_t x; std::cin >> x;

            a[0].push_back({x});
        } else if (type == 1) {
            int64_t x, y; std::cin >> x >> y;

            a[1].push_back({x, y});
        } else if (type == 2) {
            int64_t x, z; std::cin >> x >> z;

            a[2].push_back({x, z});
        } else {
            int64_t x, y, z; std::cin >> x >> y >> z;

            a[3].push_back({x, y, z});
        }
    }

    int64_t res = 0;

    std::sort(a[3].begin(), a[3].end(), [&](std::vector<int64_t> x, std::vector<int64_t> y) {
        return x[2] * y[1] < x[1] * y[2];
    });

    {
        std::vector<std::array<int64_t, 6>> dp(N, std::array<int64_t, 6>{});

        dp[0][0] = 1;
        for (auto u: a[0])
            for (int i = N - 1; i >= u.front(); --i)
                for (int j = 0; j < 5; ++j)
                    if (dp[i - u.front()][j])
                        dp[i][j + 1] = std::max(dp[i][j + 1], dp[i - u.front()][j]);

        for (auto u: a[1])
            for (int i = N - 1; i >= u.front(); --i)
                for (int j = 0; j < 5; ++j)
                    if (dp[i - u.front()][j])
                        dp[i][j + 1] = std::max(dp[i][j + 1], dp[i - u.front()][j] + u.back());

        for (auto u: a[3])
            for (int i = N - 1; i >= u.front(); --i)
                for (int j = 0; j < 5; ++j)
                    if (dp[i - u.front()][j])
                        dp[i][j + 1] = std::max(dp[i][j + 1], (dp[i - u.front()][j] + u[1]) * u.back());

        for (auto u: a[2])
            for (int i = N - 1; i >= u.front(); --i)
                for (int j = 0; j < 5; ++j)
                    if (dp[i - u.front()][j])
                        dp[i][j + 1] = std::max(dp[i][j + 1], dp[i - u.front()][j] * u.back());

        for (int64_t i = 1; i < N; ++i) {
            res = std::max(res, i * dp[i][5]);

    //        if (dp[i][5])
    //        std::cout << i << ' ' << dp[i][5] << '\n';
        }
    }

    std::sort(a[3].begin(), a[3].end());

    if (n <= 15) {
        int cnt = 0;
        do {
            cnt++;

            std::vector<std::array<int64_t, 6>> dp(N, std::array<int64_t, 6>{});

            dp[0][0] = 1;
            for (auto u: a[0])
                for (int i = N - 1; i >= u.front(); --i)
                    for (int j = 0; j < 5; ++j)
                        if (dp[i - u.front()][j])
                            dp[i][j + 1] = std::max(dp[i][j + 1], dp[i - u.front()][j]);

            for (auto u: a[1])
                for (int i = N - 1; i >= u.front(); --i)
                    for (int j = 0; j < 5; ++j)
                        if (dp[i - u.front()][j])
                            dp[i][j + 1] = std::max(dp[i][j + 1], dp[i - u.front()][j] + u.back());

            for (auto u: a[3])
                for (int i = N - 1; i >= u.front(); --i)
                    for (int j = 0; j < 5; ++j)
                        if (dp[i - u.front()][j])
                            dp[i][j + 1] = std::max(dp[i][j + 1], (dp[i - u.front()][j] + u[1]) * u.back());

            for (auto u: a[2])
                for (int i = N - 1; i >= u.front(); --i)
                    for (int j = 0; j < 5; ++j)
                        if (dp[i - u.front()][j])
                            dp[i][j + 1] = std::max(dp[i][j + 1], dp[i - u.front()][j] * u.back());

            for (int64_t i = 1; i < N; ++i) {
                res = std::max(res, i * dp[i][5]);

        //        if (dp[i][5])
        //        std::cout << i << ' ' << dp[i][5] << '\n';
            }

            if (cnt > 500)
                break;

        } while (next_permutation(a[3].begin(), a[3].end()));
    }

    std::cout << res << '\n';
    return 0;
}
