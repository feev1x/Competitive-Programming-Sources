/**
 *    author:  feev1x
 *    created: 11.08.2025 17:15:25
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

inline void update(std::pair<int, int64_t> &a, std::pair<int, int64_t> b) {
    if (b.second == 0)
        return;

    if (a.first > b.first || a.second == 0)
        a = b;
    else if (a.first == b.first)
        a.second += b.second;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int64_t k; std::cin >> k;

    int n = s.size();
    s = " " + s;


    int m, mn;
    auto Dp = [&](int xx, int yy, int zz, int ls) {
        std::vector dp(m + 1, std::vector(n + 1, std::vector(mn + 1, std::array<int64_t, 2>{})));

        dp[xx][yy][zz][ls] = 1;
        for (int i = std::max(1, xx); i <= m; ++i)
            for (int j = yy; j <= n; ++j)
                for (int k = 0; k <= mn; ++k) {
                    if (j - 1 >= 0 && (s[j] != '-' || s[j - 1] != '-'))
                        dp[i][j][k][0] += dp[i - 1][j - 1][k][0];

                    if (j - 1 >= 0)
                        dp[i][j][k][0] += dp[i - 1][j - 1][k][1];

                    if (k - 1 >= 0)
                        dp[i][j][k][1] += dp[i - 1][j][k - 1][0] + dp[i - 1][j][k - 1][1];

                    if (k + 1 <= mn)
                        dp[i][j][k][1] += dp[i - 1][j][k + 1][0] + dp[i - 1][j][k + 1][1];
                }

        return dp[m][n][0][0] + dp[m][n][0][1];
    };

    mn = 0;
    for (int i = 1; i + 1 <= n; ++i)
        if (s[i] == '-' && s[i + 1] == '-')
            mn++;

    mn = (mn + 1) / 2;
    m = mn * 2 + n;
    int64_t CNT = Dp(0, 0, 0, 1);

    if (CNT < k) {
        std::cout << "Overflow\n";
        exit(0);
    }

    if (mn == 0) {
        std::cout << s << '\n';
        exit(0);
    }

    std::string res;

    int y = 0, z = 0, ls = 1;
    for (int x = 1; x <= m; ++x) {
//        std::cerr << x << ' ' << y << ' ' << z << ' ' << ls << '\n';

        if (y != n && (ls != 0 || y == 0 || s[y] != '-' || s[y + 1] != '-')) {
            int64_t cnt = Dp(x, y + 1, z, 0);

            if (cnt >= k) {
                ls = 0;
                res += s[++y];
                continue;
            }

            k -= cnt;
        }

        if (z + 1 <= mn) {
            int64_t cnt = Dp(x, y, z + 1, 1);

            if (cnt >= k) {
                z++;
                ls = 1;
                res += "{";
                continue;
            }
            
            k -= cnt;
        }

        if (z - 1 >= 0) {
            int64_t cnt = Dp(x, y, z - 1, 1);

            if (cnt >= k) {
                z--;
                ls = 1;
                res += "}";
                continue;
            }
            
            k -= cnt;
        }

        assert(false);
    }

    assert(k == 1);
    std::cout << res << '\n';
    return 0;
}
