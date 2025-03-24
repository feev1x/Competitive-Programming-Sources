/**
 *    author:  feev1x
 *    created: 06.03.2025 13:49:06
**/
#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    int n, cnt;

    Dsu(int _n) : n(_n), cnt(n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline bool unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            p[u] = v;
            sz[v] += sz[u];

            return true;
        }

        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        Dsu d(n);
        std::map<int, std::map<int, bool>> mp;
        std::vector<int> a(n + 1);
        int cnt = n, closed = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            if (mp[i][a[i]]) {
                continue;
            }

            mp[i][a[i]] = mp[a[i]][i] = true;

            if (d.unite(i, a[i])) {
                cnt--;
            } else {
                closed++;
            }
        }

        std::cout << std::min(cnt, closed + 1) << ' ' << cnt << '\n';
    }
    return 0;
}
