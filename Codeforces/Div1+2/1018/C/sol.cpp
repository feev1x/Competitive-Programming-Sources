#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

template<class T>
inline void chmin(T &a, T b) {
    if (a > b) {
        a = b;
    }
}

inline void solve() {
    int n; std::cin >> n;

    std::vector h(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> h[i][j];
        }
    }

    std::vector<int> a(n), b(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    std::vector<std::array<int64_t, 2>> dp(n, {INF, INF});
    std::vector<std::array<int64_t, 2>> dp2(n, {INF, INF});

    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; ++i) {
        for (int add = 0; add < 2; ++add) {
            for (int nadd = 0; nadd < 2; ++nadd) {
                bool flag = true;

                for (int j = 0; j < n; ++j) {
                    if (h[i][j] + nadd == h[i - 1][j] + add) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    chmin(dp[i][nadd], dp[i - 1][add] + a[i] * nadd);
                }
            }
        }
    }

    dp2[0][0] = 0;
    dp2[0][1] = b[0];
    for (int i = 1; i < n; ++i) {
        for (int add = 0; add < 2; ++add) {
            for (int nadd = 0; nadd < 2; ++nadd) {
                bool flag = true;

                for (int j = 0; j < n; ++j) {
                    if (h[j][i] + nadd == h[j][i - 1] + add) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    chmin(dp2[i][nadd], dp2[i - 1][add] + b[i] * nadd);
                }
            }
        }
    }

    int64_t r = std::min(dp[n - 1][0], dp[n - 1][1]);
    int64_t c = std::min(dp2[n - 1][0], dp2[n - 1][1]);
    std::cout << (r == INF || c == INF ? (int64_t)-1 : r + c) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
