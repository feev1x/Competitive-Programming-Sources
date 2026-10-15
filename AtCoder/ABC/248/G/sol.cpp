#include <bits/stdc++.h>

constexpr int N = 1e5 + 5, MOD = 998244353;

inline int mul(int a, int b) { return (int64_t)a * b % MOD; };

inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::vector<bool> prime(N, true);
    prime[1] = false;
    std::vector<std::vector<int>> dv(N);
    std::vector<int> pr(N);
    for (int i = 2; i < N; ++i) {
        if (!prime[i]) continue;
        pr[i] = 1;
        for (int j = i * 2; j < N; j += i) {
            prime[j] = false;
            int u = j;
            while (u % i == 0) u /= i, pr[j]++;
        }
    }
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i) dv[j].emplace_back(i);
    int n; std::cin >> n;   
    std::vector<int> a(n + 1), sz(n + 1);
    std::vector<bool> used(n + 1), here(n + 1);
    std::vector<std::vector<int>> g(n + 1), val(N), adj(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i], val[a[i]].emplace_back(i);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<std::map<int, int>> dp(n + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        dp[v][a[v]] = 1;
        for (auto to: g[v]) {
            if (to == p) continue;
            self(self, to, v);
            for (auto [key, val]: 
        }
    };
    Dfs(Dfs, 1, 1);
    std::cout << res << '\n';
    return 0;
}

/*
 * 6-2
 * 4-2
 * 1-7
 * 2-3
 * 7-2
 * */























