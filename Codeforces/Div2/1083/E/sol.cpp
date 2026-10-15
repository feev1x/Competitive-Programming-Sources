#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline std::vector<int> z_fun(std::vector<int> a) {
    int n = a.size();

    std::vector<int> z(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }

        while (i + z[i] < n && a[z[i]] == a[i + z[i]]) {
            z[i]++;
        }

        if (i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }

    return z;
}

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(n + 1, true));
    for (int i = 1; i <= n; ++i) {
        std::vector<int> b;

        for (int j = i; j <= n; ++j) {
            b.emplace_back(a[j]);
        }

        auto z = z_fun(b);

        int r = -1;
        for (int j = i; j <= n; ++j) {
            r = std::max(r, z[j - i] + j);

            if (a[i] == a[j] || j < r) {
                dp[i][j] = false;
            }
        }

        dp[i][i] = true;
    }

    std::vector<int> ans(n + 1);
    
    ans[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j + 1][i]) {
                add_self(ans[i], ans[j]);
            }
        }
    }

    std::cout << ans[n] << '\n';
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
