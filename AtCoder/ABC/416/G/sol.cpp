/**
 *    author:  feev1x
 *    created: 26.07.2025 18:07:16
**/
#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<std::string> s(n);
    for (auto &u: s)
        std::cin >> u;

    std::string mn;
    for (auto u: s)
        if (mn.empty() || u + mn < mn + u || u + mn == mn + u && u < mn)
            mn = u;

    std::vector upd(mn.size(), std::vector<int>(mn.size(), INF));
    for (int i = 0; i < mn.size(); ++i)
        for (int j = 0; j < n; ++j) {
            bool flag = true;

            int idx = i;
            for (auto u: s[j]) {
                if (mn[idx] != u) {
                    flag = false;
                    break;
                }

                idx = (idx + 1) % (int)mn.size();
            }

            idx = (i + (int)s[j].size()) % (int)mn.size();
            if (flag)
                upd[i][idx] = std::min(upd[i][idx], (int)s[j].size());
        }

    std::vector dp(k + 1, std::vector<int>(mn.size(), INF));

    dp[0][0] = 0;
    for (int i = 1; i <= k; ++i)
        for (int j = 0; j < mn.size(); ++j)
            for (int l = 0; l < mn.size(); ++l)
                dp[i][l] = std::min(dp[i][l], dp[i - 1][j] + upd[j][l]);


    int sz = *std::min_element(dp[k].begin(), dp[k].end());

    std::string res;
    while (res.size() < sz)
        res += mn;

    while (res.size() > sz)
        res.pop_back();

    std::cout << res << '\n';
    return 0;
}

