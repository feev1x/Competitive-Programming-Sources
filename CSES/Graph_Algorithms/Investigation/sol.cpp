/**
 *    author:  feev1x
 *    created: 03.03.2025 22:44:28
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;
constexpr int64_t INF = 1e18;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int64_t>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w; std::cin >> u >> v >> w;

        g[u].emplace_back(v, w);
    }

    std::vector<int64_t> dis(n + 1, INF), mn(n + 1, INF), mx(n + 1, -INF);
    std::vector<int> cnt(n + 1);
    dis[1] = 0, cnt[1] = 1, mn[1] = 0, mx[1] = 0;

    std::set<std::array<int64_t, 3>> st;

    st.insert({dis[1], 0, 1});
    while (st.size()) {
        auto [_, p_sz, v] = *st.begin();

        st.erase(st.begin());
        for (auto [to, w]: g[v]) {
            if (dis[to] > dis[v] + w) {
                st.erase({dis[to], mn[to], to});

                dis[to] = dis[v] + w;
                cnt[to] = cnt[v];
                mn[to] = mn[v] + 1;

                st.insert({dis[to], mn[to], to});
            } else if (dis[to] == dis[v] + w) {
                st.erase({dis[to], mn[to], to});

                add_self(cnt[to], cnt[v]);
                mn[to] = std::min(mn[to], mn[v] + 1);

                st.insert({dis[to], mn[to], to});
            }
        }
    }

    std::fill(dis.begin(), dis.end(), INF);
    std::fill(cnt.begin(), cnt.end(), 0);

    dis[1] = 0, cnt[1] = 1;

    st.insert({dis[1], 0, 1});
    while (st.size()) {
        auto [_, p_sz, v] = *st.begin();

        st.erase(st.begin());
        for (auto [to, w]: g[v]) {
            if (dis[to] > dis[v] + w) {
                st.erase({dis[to], -mx[to], to});

                dis[to] = dis[v] + w;
                cnt[to] = cnt[v];
                mx[to] = mx[v] + 1;

                st.insert({dis[to], -mx[to], to});
            } else if (dis[to] == dis[v] + w) {
                st.erase({dis[to], -mx[to], to});

                add_self(cnt[to], cnt[v]);
                mx[to] = std::max(mx[to], mx[v] + 1);

                st.insert({dis[to], -mx[to], to});
            }
        }
    }

    std::cout << dis[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
    return 0;
}
