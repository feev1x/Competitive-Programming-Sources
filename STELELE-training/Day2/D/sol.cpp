/**
 *    author:  feev1x
 *    created: 13.10.2025 10:57:15
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
    std::vector<int> p, sz, mxh;
    int n;

    Dsu(std::vector<int> _mxh) : mxh(_mxh), n(mxh.size()) {
        p.resize(n);
        sz.assign(n, 1);

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

            mxh[v] = std::max(mxh[v], mxh[u]);
            p[u] = v;
            sz[v] += sz[u];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<std::array<int, 3>> a(n);
        for (auto &[l, r, h]: a)
            std::cin >> l >> r >> h;

        std::sort(a.begin(), a.end(), [](std::array<int, 3> x, std::array<int, 3> y) {
            if (x[0] == y[0])
                return x[1] > y[1];

            return x[0] < y[0];
        });

        std::set<std::pair<int, int>> st;

        std::vector<int> mxh;
        for (int i = 0; i < n; ++i)
            mxh.emplace_back(a[i][2]);

        Dsu d(mxh);
        for (int i = 0; i < n; ++i) {
            auto [l, r, h] = a[i];
            
            int mx = r;
            while (st.size() && st.rbegin()->first >= r) {
                mx = std::max(mx, st.rbegin()->first);

                d.unite(i, st.rbegin()->second);

                st.erase(--st.end());
            }

            st.emplace(mx, i);
        }

        int64_t sum = 0;
        for (int i = 0; i < n; ++i)
            sum += d.mxh[d.get(i)];

        std::cout << sum << '\n';
    }
    return 0;
}
