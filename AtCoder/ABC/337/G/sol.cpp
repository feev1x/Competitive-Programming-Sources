/**
 *    author:  feev1x
 *    created: 17.10.2025 08:21:57
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

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r) {
        for (; r <= n; r += r & -r)
            p[r]++;
    }

    inline int get(int r) {
        int res = 0;

        for (; r > 0; r -= r & -r)
            res += p[r];

        return res;
    }

    inline int get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> add(n + 1), ans(n + 1);
    std::vector<int> sz(n + 1), tin(n + 1), tout(n + 1), par(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int _t = 0;

    {
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            sz[v] = 1;
            tin[v] = ++_t;
            par[v] = p;

            for (auto to: g[v]) {
                if (to == p)
                    continue;

                self(self, to, v);
                sz[v] += sz[to];
            }

            tout[v] = _t;
        };

        Dfs(Dfs, 1, 1);
    }

    Bit bit(n);
    int64_t all = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto to: g[i]) {
            if (to == par[i])
                continue;

            int subs = bit.get(tin[to], tout[to]), oths = i - 1 - subs;

            all += subs;
            add[to] -= subs;
        }

        int subs = bit.get(tin[i], tout[i]), oths = i - 1 - subs;

        add[i] += oths;

//        for (auto to: g[i])
//            if (to != par[i])
//                add[to] -= oths;

        bit.update(tin[i]);
    }

    int64_t sum = all;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        sum += add[v];

        ans[v] = sum;
        for (auto to: g[v])
            if (to != p)
                self(self, to, v);

        sum -= add[v];
    };

    Dfs(Dfs, 1, 1);

    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];

    return 0;
}
