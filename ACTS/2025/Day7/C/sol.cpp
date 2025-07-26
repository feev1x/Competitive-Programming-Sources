#include <bits/stdc++.h>

constexpr int64_t MOD = 3e18 + 1;

#define int int64_t

inline void chmin(int &a, int b) {
    if (a > b)
        a = b;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    int64_t cnt = 0;
    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];

        for (int j = 1; j <= m; ++j)
            cnt += (s[i][j] == '.');
    }

    std::vector<std::vector<bool>> dp(n + 2, std::vector<bool>(m + 2));
    std::vector<std::vector<bool>> top(n + 2, std::vector<bool>(m + 2));
    std::vector<std::vector<bool>> bot(n + 2, std::vector<bool>(m + 2));

    dp[0][1] = true;
    dp[1][0] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*')
                continue;

            dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
        }

    dp[n + 1][m] = dp[n][m + 1] = true;
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            dp[i][j] = dp[i][j] & (dp[i + 1][j] | dp[i][j + 1]);


    if (!dp[n][m]) {
        std::cout << cnt * (cnt - 1) / 2 << '\n';

        exit(0);
    }

    top[n][m] = true;
    for (int i = 1, j = 1; i != n || j != m;) {
        top[i][j] = true;

        if (dp[i][j + 1])
            j++;
        else
            i++;
    }

    bot[n][m] = true;

    int64_t c1 = 0, res = 0;
    for (int i = 1, j = 1; i != n || j != m;) {
        bot[i][j] = true;

        if (top[i][j])
            c1++, res += cnt - c1;

        if (dp[i + 1][j])
            i++;
        else
            j++;
    }

    c1++;
    res += cnt - c1;

    for (int i = 1, j = 1; i != n || j != m;) {
        if (!bot[i][j]) {
            int x = i + 1, y = j;

            while (!dp[x][y] || !dp[x][y - 1])
                x++;

            int r = x, c = y;
            while (r != 1 || c != 1) {
                if (!top[r][c] && bot[r][c])
                    res++;

                if ((r != x || c != y) && dp[r - 1][c])
                    r--;
                else
                    c--;
            }

            r = x, c = y;
            while (r != n || c != m) {
                if (dp[r][c + 1])
                    c++;
                else
                    r++;

                if (!top[r][c] && bot[r][c])
                    res++;
            }
        }

        if (dp[i][j + 1])
            j++;
        else
            i++;
    }

    std::cout << res << '\n';
    return 0;
}
