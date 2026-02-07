#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 2);

    s[0] = std::string(m + 2, '$');
    s[n + 1] = std::string(m + 2, '$');
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = "$" + s[i] + "$";
    }

    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};

    std::map<char, int> mp;

    mp['N'] = 1;
    mp['S'] = 0;
    mp['W'] = 3;
    mp['E'] = 2;

    std::vector dp(n + 2, std::vector<int>(m + 2, INF));
    std::queue<std::pair<int, int>> q;

    dp[1][1] = 0;
    q.emplace(1, 1);
    while (q.size()) {
        auto [i, j] = q.front();

        q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = dx[k] + i, y = dy[k] + j, add = mp[s[i][j]] != k;

            if (s[x][y] != '$' && dp[x][y] > dp[i][j] + add) {
                dp[x][y] = dp[i][j] + add;
                q.emplace(x, y);
            }
        }
    }

    std::cout << dp[n][m] << '\n';
    return 0;
}
