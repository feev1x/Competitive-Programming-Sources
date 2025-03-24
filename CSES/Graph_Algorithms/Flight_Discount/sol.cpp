/**
 *    author:  feev1x
 *    created: 03.03.2025 18:30:33
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
    }

    std::vector<std::array<int64_t, 2>> dis(n + 1, {INF, INF});
    dis[1][0] = 0;

    std::set<std::array<int64_t, 3>> st;

    st.insert({dis[1][0], 1, 0});
    while (st.size()) {
        auto [d, v, cnt] = *st.begin();

        st.erase(st.begin());

        for (auto [to, w]: g[v]) {
            if (dis[to][cnt] > d + w) {
                st.erase({dis[to][cnt], to, cnt});

                dis[to][cnt] = d + w;
                st.insert({dis[to][cnt], to, cnt});
            }

            if (!cnt && dis[to][1] > d + w / 2) {
                st.erase({dis[to][1], to, 1ll});

                dis[to][1] = d + w / 2;
                st.insert({dis[to][1], to, 1ll});
            }
        }
    }

    std::cout << dis[n][1] << '\n';
    return 0;
}
