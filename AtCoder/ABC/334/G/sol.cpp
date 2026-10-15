#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline int mul(int a, int b) { return (int64_t)a * b % MOD; }
inline int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a), n >>= 1;
    }
    return res;
}

inline int divide(int a, int b) { return mul(a, binpow(b, MOD - 2)); }
inline void add_self(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int h, w, _t = 0, res = 0, green = 0; std::cin >> h >> w;
    std::vector<std::string> s(h);
    for (auto &u: s) std::cin >> u, green += std::count(u.begin(), u.end(), '#');
    auto Idx = [&](int i, int j) { return i * w + j; };
    int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
    std::vector<bool> good(h * w);
    std::vector<std::vector<int>> g(h * w);
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (s[i][j] == '#') {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (std::min(x, y) >= 0 && x < h && y < w && s[x][y] == '#') {
                        g[Idx(i, j)].emplace_back(Idx(x, y));
                        g[Idx(x, y)].emplace_back(Idx(i, j));
                    }
                }
                good[Idx(i, j)] = true;
            }
    std::vector<int> tin(h * w), low(h * w);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        int cnt = 0;
        tin[v] = low[v] = ++_t;
        for (auto to: g[v]) {
            if (to == p) continue;
            if (tin[to]) low[v] = std::min(low[v], tin[to]);
            else {
                self(self, to, v);
                low[v] = std::min(low[v], low[to]);
                if (low[to] >= tin[v]) {
                    cnt++;
                }
            }
        }
        if (p == v && g[v].empty()) return add_self(res, divide(MOD - 1, green));
        if (p != v) cnt++;
        if (cnt > 1) add_self(res, divide(cnt - 1, green));
    };
    for (int i = 0; i < h * w; ++i) if (good[i] && !tin[i]) Dfs(Dfs, i, i), add_self(res, 1);
    std::cout << res <<'\n';
    return 0;
}
