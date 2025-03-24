/**
 *    author:  feev1x
 *    created: 03.03.2025 15:21:19
**/
#include <bits/stdc++.h>

using digit_dp = std::vector<std::vector<std::vector<int64_t>>>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t a, b; std::cin >> a >> b; a--;

    std::string s1 = std::to_string(a), s2 = std::to_string(b);

    digit_dp dp1(s1.size() + 1, std::vector(10, std::vector<int64_t>(3)));
    digit_dp dp2(s2.size() + 1, std::vector(10, std::vector<int64_t>(3)));

    auto Calc = [](digit_dp &dp, std::string s) -> void {
        for (int j = 1; j < 10; ++j) {
            if (j < s[0] - '0') {
                dp[1][j][0] = 1;
            }

            if (j == s[0] - '0') {
                dp[1][j][1] = 1;
            }

            dp[1][j][2] = 1;
        }

        for (int i = 2; i <= s.size(); ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 10; ++k) {
                    if (j == k) {
                        continue;
                    }

                    dp[i][j][2] += dp[i - 1][k][2];
                    dp[i][j][0] += dp[i - 1][k][0];    

                    if (j > s[i - 1] - '0') {
                        // skip    
                    } else if (j == s[i - 1] - '0') {
                        dp[i][j][1] += dp[i - 1][k][1];
                    } else {
                        dp[i][j][0] += dp[i - 1][k][1];
                    }
                }
            }
        }
    };

    Calc(dp1, s1);
    Calc(dp2, s2);

    auto Count = [](digit_dp &dp, std::string s) -> int64_t {
        int64_t res = 0;

        for (int i = 0; i < 10; ++i) {
            res += dp[s.size()][i][0] + dp[s.size()][i][1];
        }

        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; j < 10; ++j) {
                res += dp[i][j][2];
            }
        }
        
        return res;
    };

    std::cout << Count(dp2, s2) - (a == -1 ? -1 : Count(dp1, s1)) << '\n';
    return 0;
}
