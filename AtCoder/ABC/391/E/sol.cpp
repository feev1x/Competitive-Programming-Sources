/**
 *    author:  feev1x
 *    created: 01.02.2025 18:57:43
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n; n++;
    std::vector<std::string> s(n + 1); std::cin >> s[1];

    std::vector<std::vector<bool>> used(n + 1);
    std::vector<std::vector<int>> dp(n + 1);
    used[1].resize(s[1].size());
    dp[1].resize(s[1].size());
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < s[i - 1].size(); j += 3) {
            std::string s1 = s[i - 1].substr(j, 3);
            
            std::sort(s1.begin(), s1.end());

            s[i] += s1[1];
        }

        used[i].resize(s[i].size());
        dp[i].resize(s[i].size());
    }

    auto Dfs = [&](auto &&self, int i, int j) {
        if (used[i][j]) {
            return dp[i][j];
        }

        if (i == 1) {
            return 1;
        }

        used[i][j] = true;
        int l = j * 3, cnt = 0;

        for (int k = l; k <= l + 2; ++k) {
            if (s[i - 1][k] != s[i][j]) {
                cnt++;
            }
        }

        assert(cnt < 2);

        int res = INF;
        if (cnt == 1) {
            for (int k = l; k <= l + 2; ++k) {
                if (s[i - 1][k] == s[i][j]) {
                    res = std::min(res, self(self, i - 1, k));
                }
            }
        } else {
            for (int k = l; k <= l + 2; ++k) {
                if (s[i - 1][k] != s[i][j]) {
                    continue;
                }

                for (int k1 = k + 1; k1 <= l + 2; ++k1) {
                    if (s[i - 1][k1] == s[i][j]) {
                        res = std::min(res, self(self, i - 1, k1) + self(self, i - 1, k));
                    }
                }
            }
        }

        return dp[i][j] = res;
    };

    std::cout << Dfs(Dfs, n, 0) << '\n';
    return 0;
}
