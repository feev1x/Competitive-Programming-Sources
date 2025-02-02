/**
 *    author:  feev1x
 *    created: 10.01.2025 10:20:42
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    int sl, sc, el, ec; std::cin >> sl >> sc >> el >> ec; sc--, ec--;

    std::vector<int> l(n + 1);
    std::vector<std::vector<std::pair<int, int>>> g(2 * n + 2);
    for (int i = 1; i <= n; ++i) {
        std::cin >> l[i];

        g[2 * i].emplace_back(2 * i + 1, l[i]);
        g[2 * i + 1].emplace_back(2 * i, l[i]);

        if (i != 1) {
            g[2 * i].emplace_back(2 * (i - 1) + 1, 1);
            g[2 * i].emplace_back(2 * (i - 1), 1);
        }

        if (i != n) {
            g[2 * i + 1].emplace_back(2 * (i + 1), 1);
            g[2 * i].emplace_back(2 * (i + 1), 1);
        }

        g[0].emplace_back(2 * i, std::abs(i - sl) + sc);
        g[2 * i].emplace_back(1, std::abs(i - el) + ec);
    }

    int mn = sc;
    for (int i = sl; i >= 1; --i) {
        mn = std::min(mn, l[i]);
        g[0].emplace_back(2 * i + 1, std::abs(sl - i) + l[i] - mn);
    }

    mn = sc;
    for (int i = sl; i <= n; ++i) {
        mn = std::min(mn, l[i]);
        g[0].emplace_back(2 * i + 1, std::abs(sl - i) + l[i] - mn);
    }

    mn = INF;
    for (int i = el; i >= 1; --i) {
        if (mn > l[i]) {
            mn = l[i];
            g[2 * i + 1].emplace_back(1, std::abs(el - i) + std::abs(mn - ec));
        }
    }

    mn = INF;
    for (int i = el; i <= n; ++i) {
        if (mn > l[i]) {
            mn = l[i];
            g[2 * i + 1].emplace_back(1, std::abs(el - i) + std::abs(mn - ec));
        }
    }

    std::vector<int> dis(2 * n + 2, INF);
    dis[0] = 0;

    std::set<std::pair<int, int>> st;
    st.emplace(0, 0);
    while (st.size()) {
        int v = st.begin()->second;
        st.erase(st.begin());

        for (auto [to, w]: g[v]) {
            if (dis[to] > dis[v] + w) {
                st.erase({dis[to], to});
                dis[to] = dis[v] + w;
                st.emplace(dis[to], to);
            }
        }
    }

    bool flag = true;
    for (int i = std::min(sl, el); i <= std::max(sl, el); ++i) {
        if (std::min(sc, ec) > l[i]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        dis[1] = std::min(dis[1], std::abs(sl - el) + std::abs(sc - ec));
    }

    std::cout << dis[1] << '\n';
    return 0;
}
