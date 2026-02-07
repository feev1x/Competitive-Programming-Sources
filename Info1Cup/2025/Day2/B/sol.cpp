#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, N = 5e5 + 5;
int dp[N];

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return a * b % MOD;
}

inline void solve() {
    int n; std::cin >> n;

    std::cout << dp[n] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[1] = 1;
    dp[0] = 1;
    std::vector<std::vector<int>> g(N);
    for (int i = 2; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            g[j].emplace_back(j / i);
        }
    }

    for (int i = 2; i < N; ++i) {
        add_self(dp[i], dp[i - 1]);

        for (auto u: g[i]) {
            add_self(dp[i], dp[u - 1]);
        }
    }


    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
