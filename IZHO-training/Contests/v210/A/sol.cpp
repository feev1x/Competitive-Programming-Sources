#include <bits/stdc++.h>

struct Sptable {
    std::vector<std::vector<int>> sp;
    std::vector<int> log;
    std::function<int(int, int)> f;
    int n;

    Sptable(std::vector<int> a, std::function<int(int, int)> f) : n(a.size() - 1), f(f) {
        log.resize(n + 1);

        for (int i = 2; i <= n; ++i) {
            log[i] = log[i / 2] + 1;
        }

        sp.resize(log[n] + 1, std::vector<int>(n + 1));

        sp[0] = a;
        for (int i = 1; i <= log[n]; ++i) {
            for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
                sp[i][j] = f(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
            }
        }
    }

    inline int get(int l, int r) {
        int i = log[r - l + 1];

        return f(sp[i][l], sp[i][r - (1 << i) + 1]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = ' ' + s[i];
    }

    auto Min = [](int a, int b) {
        if (a > b) {
            return b;
        }

        return a;
    };

    auto Max = [](int a, int b) {
        if (a < b) {
            return b;
        }

        return a;
    };

    std::vector<std::vector<int>> p(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + (s[i][j] == 'X' ? 0 : s[i][j] - '0');
        }
    }

    auto Sum = [&](int x, int y, int x2, int y2) {
        if (x > x2) {
            std::swap(x, x2);
        }

        if (y > y2) {
            std::swap(y, y2);
        }

        return p[x2][y2] - p[x - 1][y2] - p[x2][y - 1] + p[x - 1][y - 1];
    };

    std::vector<int> oleft(n + 1), oright(n + 1, n + 1);
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    int res = 0;
    for (int k = 1; k < m; ++k) {
        std::vector<int> left(n + 1), dpl(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            left[i] = (s[i][k] == 'X' ? k : oleft[i]);
        }

        Sptable sl(left, Max);
        for (int i = 1; i <= n; ++i) {
            if (left[i] < k) {
                int l = 1, r = i - 1, ans = i;

                while (l <= r) {
                    int mid = l + r >> 1;

                    if (sl.get(mid, i) > left[i]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1, ans = mid;
                    }
                }

                dpl[i] = dpl[ans - 1] + Sum(i, k, ans, left[i] + 1);
            }
        }

        dp[k] = dpl;
        oleft = left;
    }

    for (int k = m - 1; k > 0; --k) {
        std::vector<int> right(n + 1), dpr(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            right[i] = (s[i][k + 1] == 'X' ? k + 1 : oright[i]);
        }

        Sptable sr(right, Min);
        for (int i = 1; i <= n; ++i) {
            if (right[i] > k + 1) {
                int l = 1, r = i - 1, ans = i;

                while (l <= r) {
                    int mid = l + r >> 1;

                    if (sr.get(mid, i) < right[i]) {
                        l = mid + 1;
                    } else {
                        r = mid - 1, ans = mid;
                    }
                }

                dpr[i] = dpr[ans - 1] + Sum(i, k + 1, ans, right[i] - 1);
            }

            res = std::max(res, dp[k][i] + dpr[i]);
        }

        oright = right;
    }

    std::cout << res << '\n';
    return 0;
}
