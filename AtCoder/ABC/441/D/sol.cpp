#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, l, s, t; std::cin >> n >> m >> l >> s >> t;

    std::vector<std::vector<std::pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c; std::cin >> u >> v >> c;

        g[u].emplace_back(v, c);
    }

    std::set<int> st;

    std::vector<int> pw(l + 1, 1);
    for (int i = 1; i <= l; ++i) {
        pw[i] = pw[i - 1] * 4;
    }

    for (int mask = 0; mask < pw[l]; ++mask) {
        bool val = true;

        int64_t cost = 0;
        int nw = 1;
        for (int i = 0; i < l; ++i) {
            int vl = mask / pw[i] % 4;

            if (g[nw].size() <= vl) {
                val = false;
                break;
            }

            cost += g[nw][vl].second;
            nw = g[nw][vl].first;
        }
        
        if (val && s <= cost && cost <= t) {
            st.emplace(nw);
        }
    }


    for (auto u: st) {
        std::cout << u << ' ';
    }

    std::cout << '\n';
    return 0;
}
