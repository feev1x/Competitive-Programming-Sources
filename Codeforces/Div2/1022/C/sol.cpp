/**
 *    author:  feev1x
 *    created: 01.05.2025 20:54:36
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> sz, p, cl;
    int n;

    Dsu(int _n) : n(_n) {
        sz.assign(n + 1, 1);
        cl.assign(n + 1, -1);
        p.resize(n + 1);

        std::iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            p[u] = v;
            sz[v] += sz[u];
            cl[v] = 1;
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);
        std::map<int, std::vector<int>> mp;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            mp[-a[i]].emplace_back(i);
        }

        Dsu d(n);


        int res = 0;
        for (auto [key, val]: mp) {
            for (auto i: val) {
                if (i - 1 > 0 && d.cl[d.get(i - 1)] == 1) {
                    d.unite(i, i - 1);
                }

                if (i + 1 <= n && d.cl[d.get(i + 1)] == 1) {
                    d.unite(i, i + 1);
                }
            }

            for (auto i: val) {
                if (d.cl[d.get(i)] == 1) {
                    int j = i;

                    while (i - 1 > 0 && d.get(i - 1) != d.get(i) && a[i - 1] == a[i]) {
                        d.unite(i, i - 1);
                        i--;
                    }

                    i = j;

                    while (i + 1 <= n && d.get(i + 1) != d.get(i) && a[i + 1] == a[i]) {
                        d.unite(i, i + 1);
                        ++i;
                    }
                }
            }

            for (auto i: val) {
                if (d.cl[d.get(i)] == -1 && (i + 1 > n || a[i + 1] != a[i])) {
                    res++;

                    d.cl[d.get(i)] = 1;
                }
            }

            for (auto i: val) {
                if (d.cl[d.get(i)] == 1) {
                    int j = i;

                    while (i - 1 > 0 && d.get(i - 1) != d.get(i) && a[i - 1] == a[i]) {
                        d.unite(i, i - 1);
                        --i;
                    }

                    i = j;

                    while (i + 1 <= n && d.get(i + 1) != d.get(i) && a[i + 1] == a[i]) {
                        d.unite(i, i + 1);
                        i++;
                    }
                }
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
