/**
 *    author:  feev1x
 *    created: 19.03.2025 14:07:31
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    std::map<char, int> cnt;
    std::map<int, std::map<int, std::map<int, std::map<int, int>>>> mp;

    int c2 = 0, c3 = 0, c5 = 0, c7 = 0;

    bool flag = false;
    int c2e = 0, c3e = 0, c5e = 0, c7e = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '=') {
            flag = true;

            continue;
        }
    
        if (s[i] == '*') {
            continue;
        }

        if (!flag) {
            if ('0' <= s[i] && s[i] <= '9') {
                int dig = s[i] - '0';

                while (dig % 2 == 0) {
                    c2++;

                    dig /= 2;
                }

                while (dig % 3 == 0) {
                    c3++;

                    dig /= 3;
                }

                while (dig % 5 == 0) {
                    c5++;

                    dig /= 5;
                }

                while (dig % 7 == 0) {
                    c7++;

                    dig /= 7;
                }
            } else {
                cnt[s[i]]++;
            }
        } else {
            int dig = s[i] - '0';

            while (dig % 2 == 0) {
                c2e++;

                dig /= 2;
            }

            while (dig % 3 == 0) {
                c3e++;

                dig /= 3;
            }

            while (dig % 5 == 0) {
                c5e++;

                dig /= 5;
            }

            while (dig % 7 == 0) {
                c7e++;

                dig /= 7;
            }

        }
    }

    if (c2 > c2e || c3 > c3e || c5 > c5e || c7 > c7e) {
        std::cout << "0\n";

        exit(0);
    }

    c2e -= c2, c3e -= c3, c5e -= c5, c7e -= c7;

    int n = std::max({c2e, c3e, c5e, c7e});
    std::vector<int> dp(n + 1);
    dp[0] = 1;

    for (auto [key, val]: cnt) {
        auto new_dp = dp;

        for (int i = 1; val * i <= n; ++i) {
            for (int j = 0; j + val * i <= n; ++j) {
                add_self(new_dp[j + val * i], dp[j]);
            }
        }

        dp = new_dp;
    }

    std::cout << mul(mul(dp[c2e], dp[c3e]), mul(dp[c5e], dp[c7e])) << '\n';
    return 0;
}
