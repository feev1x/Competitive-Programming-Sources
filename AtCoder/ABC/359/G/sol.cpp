#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<int> a(n + 1), cnt(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    auto b = a;
    std::sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        mx = std::max(mx, a[i]);
        cnt[a[i]]++;
    }
    int64_t res = 0;
    std::vector<int64_t> ans(n + 1);
    std::vector<std::vector<int>> ver(n + 1);
    std::vector<std::map<int, int64_t>> sub(n + 1);
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        ver[v].emplace_back(v);
        sub[v][a[v]]++;
        ans[v] = 1ll * (cnt[a[v]] - 1ll);
        for (auto to: g[v]) { 
            if (to == p) {
                continue;
            }
            self(self, to, v);
            if (ver[v].size() < ver[to].size()) {
                std::swap(ver[v], ver[to]);
                std::swap(sub[v], sub[to]);
                std::swap(ans[v], ans[to]);
            }
            for (auto u: ver[to]) {
                ver[v].emplace_back(u);
                ans[v] -= sub[v][a[u]] * (cnt[a[u]] - sub[v][a[u]]);
                sub[v][a[u]]++;
                ans[v] += sub[v][a[u]] * (cnt[a[u]] - sub[v][a[u]]);
            }
        }
        res += ans[v];
    };
    Dfs(Dfs, 1, 1);
    std::cout << res << '\n';
    return 0;
}
