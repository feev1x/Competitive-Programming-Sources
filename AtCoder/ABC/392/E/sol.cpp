/**
 *    author:  feev1x
 *    created: 10.02.2025 15:43:39
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    std::set<int> st;
    int n, cnt;

    Dsu(int _n) : n(_n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(p.begin(), p.end(), 0);

        for (int i = 1; i <= n; ++i) {
            st.emplace(i);
        }

        cnt = n;
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline bool unite(int u, int v) {
        u = get(u);
        v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            p[u] = v;
            sz[v] += sz[u];
            st.erase(u);
            cnt--;

            return true;
        }

        return false;
    }

    inline int counter() {
        return cnt;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    Dsu d(n);
    std::vector<std::array<int, 3>> e;
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        if (!d.unite(u, v)) {
            e.push_back({u, v, i + 1});
        }
    }

    std::vector<std::array<int, 3>> res;
    while (d.counter() > 1) {
        assert(d.st.size() > 1);

        auto it = d.st.begin();

        auto [u, v, i] = e.back();
        e.pop_back();

        if (*it == d.get(u)) {
            ++it;
        }

        d.unite(u, *it);
        res.push_back({i, v, *it});
    }

    std::cout << res.size() << '\n';
    for (auto [u, v, nv]: res) {
        std::cout << u << ' ' << v << ' ' << nv << '\n';
    }
    return 0;
}
