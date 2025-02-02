/**
 *    author:  feev1x
 *    created: 22.01.2025 18:17:35
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<std::set<int>> g(n + 1);
        std::set<std::pair<int, int>> st;
        for (int i = 1; i < n; ++i) {
            int u, v; std::cin >> u >> v;

            g[u].emplace(v);
            g[v].emplace(u);
        }

        for (int i = 1; i <= n; ++i) {
            st.emplace(g[i].size(), i);
        }

        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            int ans = g[i].size();
            st.erase({g[i].size(), i});

            for (auto to: g[i]) {
                st.erase({g[to].size(), to});
                g[to].erase(i);
                st.emplace(g[to].size(), to);
            }

            ans += (--st.end())->first - 1;

            st.emplace(g[i].size(), i);
            for (auto to: g[i]) {
                st.erase({g[to].size(), to});
                g[to].emplace(i);
                st.emplace(g[to].size(), to);
            }

            cnt = std::max(cnt, ans);
        }

        std::cout << cnt << '\n';
    }
    return 0;
}
