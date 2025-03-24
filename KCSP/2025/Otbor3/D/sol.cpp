/**
 *    author:  feev1x
 *    created: 16.03.2025 10:50:43
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;
    int n = s.size();

    assert(s[0] != '0');
    assert(s.back() < '2');

    std::vector<int64_t> dp(n + 1, 1e18), p(n + 1);
    std::vector<bool> ism(n + 1);

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            continue;
        }

        int64_t sum = 0;
        std::string ss;

        bool one = false, zero = false;

        if (!i || (i - 2 >= 0 && ism[i - 2])) {
            one = zero = true;
        } else if (s[i - 1] == '1') {
            zero = true;
        } else {
            one = true;
        }

        for (int j = 0; j < 9 && i + j + 1 < n; ++j) {
            sum = (sum * 10) + s[i + j] - '0';
            ss += s[i + j];

            if (ss == "999999999") {
                ism[i + j] = true;
            }

            if ((s[i + j + 1] == '1' && one || s[i + j + 1] == '0' && zero) && dp[i + j + 2] > dp[i] + sum) {
                dp[i + j + 2] = dp[i] + sum;
                p[i + j + 2] = i;
            }
        }
    }

    std::cout << dp[n] << '\n';

    std::vector<std::string> res;

    for (int v = n; v; v = p[v]) {
        std::string ss;
        ss += s[v - 1];

        res.emplace_back(ss);

        ss = "";

        for (int i = p[v]; i + 1 < v; ++i) {
            ss += s[i];
        }

        res.emplace_back(ss);
    }

    std::reverse(res.begin(), res.end());
    for (auto u: res) {
        std::cout << u << ' ';
    }

    std::cout << '\n';
    return 0;
}
