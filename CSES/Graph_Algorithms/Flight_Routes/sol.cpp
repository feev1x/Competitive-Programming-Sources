/**
 *    author:  feev1x
 *    created: 03.03.2025 20:43:04
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k; std::cin >> n >> m >> k;

    std::vector<std::vector<std::pair<int, int64_t>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
    }

    std::vector<std::multiset<int64_t>> dis(n + 1);
    dis[1].emplace(0);

    std::multiset<std::pair<int64_t, int>> st;

    st.emplace(0, 1);
    while (st.size()) {
        auto [d, v] = *st.begin();

        st.erase(st.begin());

        for (auto [to, w]: g[v]) {
            if (dis[to].size() < k) {
                dis[to].emplace(d + w);

                st.emplace(d + w, to);
            } else if (*dis[to].rbegin() > d + w) {
                auto it = st.find({*dis[to].rbegin(), to});

                st.erase(it);

                dis[to].erase(--dis[to].end());
                dis[to].emplace(d + w);
                
                st.emplace(d + w, to);
            }
        }
    }

    for (auto u: dis[n]) {
        std::cout << u << ' ';
    }

    std::cout << '\n';
    return 0;
}
