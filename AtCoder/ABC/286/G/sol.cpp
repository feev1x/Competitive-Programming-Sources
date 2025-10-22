/**
 *    author:  feev1x
 *    created: 20.10.2025 14:05:31
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

struct Dsu {
    std::vector<int> p, sz;
    int n;

    Dsu(int _n) : n(_n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        std::iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline void unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v])
                std::swap(u, v);

            p[u] = v;
            sz[v] += sz[u];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;    

    Dsu d(n);
    std::vector<std::pair<int, int>> e(m + 1);
    std::vector<bool> use(m + 1, true), dg(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v; std::cin >> u >> v;

        e[i] = {u, v};
    }

    int k; std::cin >> k;
    for (int i = 0; i < k; ++i) {
        int x; std::cin >> x;

        use[x] = false;
    }

    for (int i = 1; i <= m; ++i)
        if (use[i])
            d.unite(e[i].first, e[i].second);

    int cnt = 0;
    for (int i = 1; i <= m; ++i)
        if (!use[i]) {
            auto [u, v] = e[i];

            u = d.get(u), v = d.get(v);

            cnt -= dg[u];
            cnt -= dg[v];

            dg[u] = !dg[u], dg[v] = !dg[v];

            cnt += dg[u];
            cnt += dg[v];
        }

    if (cnt == 0 || cnt == 2)
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
    return 0;
}
