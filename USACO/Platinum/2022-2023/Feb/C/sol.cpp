#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline bool chmin(int64_t &a, int64_t b) {
    if (a > b) return a = b, true;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    s = " " + s;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int _t = 0;
    std::vector<int> tin(n + 1), vl(n + 1), par(n + 1);
    auto Df = [&](auto &&self, int v, int p) -> void {
        tin[v] = ++_t;
        par[v] = p;
        vl[tin[v]] = v;
        for (auto to: g[v]) if (to != p) self(self, to, v);
    }; Df(Df, 1, 1);
    int sq = std::min(n, (int)sqrt(n) + 5);
    std::vector<int64_t> val(sq + 1);
    std::vector<std::pair<int64_t, int64_t>> res(n + 1);
    std::vector<bool> used(n + 1);
    auto Get = [&](int k) -> std::pair<int64_t, int64_t> {
        if (used[k]) return res[k];
        used[k] = true;
        std::vector dp(2, std::vector<int64_t>(n + 1, INF));
        std::vector c(2, std::vector<int64_t>(n + 1, INF));
        for (int i = n; i >= 1; --i) {
            int v = vl[i], p = par[v];
            dp[0][v] = 0;
            c[0][v] = c[1][v] = 0;
            dp[1][v] = 1;
            for (auto to: g[v]) {
                if (to == p) continue;
                if (dp[1][to] < dp[0][to]) dp[1][v] += dp[1][to], c[1][v] += c[1][to];
                else if (dp[0][to] < dp[1][to]) dp[1][v] += dp[0][to], c[1][v] += c[0][to];
                else dp[1][v] += dp[0][to], c[1][v] += std::min(c[0][to], c[1][to]);
                if (dp[1][to] + k < dp[0][to]) dp[0][v] += dp[1][to] + k, c[0][v] += c[1][to] + 1;
                else if (dp[0][to] < dp[1][to] + k) dp[0][v] += dp[0][to], c[0][v] += c[0][to];
                else dp[0][v] += dp[0][to], c[0][v] += std::min(c[0][to], c[1][to] + 1);
            }
            if (s[v] == '1') dp[0][v] = INF, c[0][v] = 0;
        }
        int64_t cnt;
        int64_t ans;
        if (dp[0][1] < dp[1][1] + k) cnt = c[0][1], ans = dp[0][1];
        else if (dp[0][1] > dp[1][1] + k) cnt = c[1][1] + 1, ans = dp[1][1] + k;
        else cnt = std::min(c[0][1], c[1][1] + 1), ans = dp[0][1];
        return res[k] = {ans, cnt};
    };
    std::vector<int> rs(n + 1);
    auto Rec = [&](auto &&self, int l, int r) -> void {
        auto [ansl, cntl] = Get(l);
        auto [ansr, cntr] = Get(r);
        if (cntl == cntr) {
            ansl -= cntl * l;
            for (int i = l; i <= r; ++i) rs[i] = ansl + cntl * i;
            return;
        }
        int m = l + r >> 1;
        self(self, l, m);
        self(self, m + 1, r);
    }; Rec(Rec, 1, n);
    for (int i = 1; i <= n; ++i) std::cout << rs[i] << '\n';
    return 0;
}
