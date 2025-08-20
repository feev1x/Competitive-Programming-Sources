/**
 *    author:  feev1x
 *    created: 19.08.2025 16:36:16
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
    
    int n; std::cin >> n;

    std::vector<std::string> s(n);
    for (auto &u: s)
        std::cin >> u;

    std::vector dp(n, std::vector<bool>(n));

    dp[0][0] = true;

    int dx[]{0, 1};
    int dy[]{1, 0};
    for (int sum = 0; sum < 2 * n - 2; ++sum) {
        char mn = 'Z';

        for (int i = 0; i <= sum && i < n; ++i) {
            int j = sum - i;

            if (!dp[i][j])
                continue;

            for (int k = 0; k < 2; ++k) {
                int x = dx[k] + i, y = dy[k] + j;

                if (x < n && y < n)
                    mn = std::min(mn, s[x][y]);
            }
        }

        for (int i = 0; i <= sum && i < n; ++i) {
            int j = sum - i;

            if (!dp[i][j])
                continue;

            for (int k = 0; k < 2; ++k) {
                int x = dx[k] + i, y = dy[k] + j;

                if (x < n && y < n && s[x][y] == mn)
                    dp[x][y] = true;
            }
        }
    }

    std::string res;
    int i = n - 1, j = n - 1;
    while (i + j) {
        for (int k = 0; k < 2; ++k) {
            int x = -dx[k] + i, y = -dy[k] + j;

            if (x >= 0 && y >= 0 && dp[x][y]) {
                res += s[i][j];
                i = x, j = y;
                break;
            }
        }
    }

    res += s[0][0];
    std::reverse(res.begin(), res.end());

    std::cout << res << '\n';
    return 0;
}
