#include <bits/stdc++.h>

constexpr int INF = 1e9;

inline void solve() {
    int n, m, k, l; std::cin >> n >> m >> k >> l;
    std::vector<int> s(k), d(l), dis(n + 1, INF);
    std::vector<bool> isd(n + 1), iss(n + 1);
    for (auto &u: s) std::cin >> u, iss[u] = 1;
    for (auto &u: d) std::cin >> u, isd[u] = 1;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dis[1] = 0;
    std::queue<int> q;
    q.emplace(1);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (auto to: g[v]) if (dis[to] > dis[v] + 1) dis[to] = dis[v] + 1, q.emplace(to);
    }
    auto rg = g;
    for (int v = 1; v <= n; ++v) {
        std::vector<int> new_g, new_rg;
        for (auto to: g[v]) if (dis[to] == dis[v] + 1) new_g.emplace_back(to);
        for (auto to: g[v]) if (dis[to] + 1 == dis[v]) new_rg.emplace_back(to);
        std::swap(g[v], new_g);
        std::swap(rg[v], new_rg);
    }
    std::vector<int> cntd(n + 1), cnts(n + 1), ucntd(n + 1), ucnts(n + 1);
    std::vector<bool> used(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        if (used[v]) return;
        used[v] = true;
        cntd[v] = isd[v];
        cnts[v] = iss[v];
        for (auto to: g[v]) {
            self(self, to);
            cntd[v] = std::max(cntd[v], isd[v] + cntd[to]);
            cnts[v] = std::max(cnts[v], iss[v] + cnts[to]);
        }
    };
    for (int i = 1; i <= n; ++i) Dfs(Dfs, i);
    std::sort(s.begin(), s.end(), [&](int i, int j) {
        return dis[i] < dis[j];
    });
    std::fill(used.begin(), used.end(), false);
    auto uDfs = [&](auto &&self, int v) -> void {
        if (used[v]) return;
        used[v] = true;
        ucntd[v] = isd[v];
        ucnts[v] = iss[v];
        for (auto to: rg[v]) {
            self(self, to);
            ucntd[v] = std::max(ucntd[v], isd[v] + ucntd[to]);
            ucnts[v] = std::max(ucnts[v], iss[v] + ucnts[to]);
        }
    };
    bool flag = true;
    for (int i = 1; i <= n; ++i) uDfs(uDfs, i);
    for (int i = 0; i < k; ++i) if (cnts[s[i]] != k - i || cntd[s[i]] == 0) { flag = false; break; }
    for (int i = 2; i <= n; ++i) {
        if (iss[i]) { std::cout << flag; continue; }
        std::cout << (flag && cnts[i] + ucnts[i] == k && cntd[i] > 0);
    }
    std::cout << '\n';
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
