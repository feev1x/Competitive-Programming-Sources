/**
 *    author:  feev1x
 *    created: 10.10.2025 09:18:15
**/
#include <bits/stdc++.h>

#define int int64_t

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

struct Segtree {
    std::vector<int64_t> t;
    int n;

    Segtree() {}
    Segtree(int _n) : n(_n) {
        t.resize(2 * n);
    }

    inline void update(int l, int r, int64_t x) {
        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                t[l++] += x;

            if (r & 1)
                t[--r] += x;
        }
    }

    inline int get(int v) {
        int64_t res = 0;

        for (v += n - 1; v; v >>= 1)
            res += t[v];

        return res;
    }
};

struct Hld {
    std::vector<int> p, head, idx, heavy, sz;
    std::vector<std::vector<int>> g;
    Segtree t;
    int n, _t;

    inline void dfs(int v) {
        sz[v] = 1;

        for (auto to: g[v]) {
            p[to] = v;

            dfs(to);

            sz[v] += sz[to];
        }
    }

    inline void dec(int v) {
        idx[v] = ++_t;

        for (auto to: g[v])
            if (sz[heavy[v]] < sz[to])
                heavy[v] = to;

        head[heavy[v]] = head[v];
        if (heavy[v])
            dec(heavy[v]);

        for (auto to: g[v])
            if (to != heavy[v])
                dec(to);
    }

    Hld(std::vector<std::vector<int>> _g) : g(_g), n(g.size() - 1) {
        p.resize(n + 1);
        head.resize(n + 1);
        heavy.resize(n + 1);
        idx.resize(n + 1);
        sz.resize(n + 1);

        for (int i = 1; i <= n; ++i)
            head[i] = i;

        _t = 0;
        p[1] = 1;
        dfs(1);

        t = Segtree(n);

        dec(1);
    }

    inline int64_t get(int v) {
        return t.get(idx[v]);
    }

    inline void update(int u, int v, int64_t x) {
        while (head[u] != head[v]) {
            t.update(idx[head[v]], idx[v], x);

            v = p[head[v]];
        }

        t.update(idx[u], idx[v], x);
    }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q, h; std::cin >> n >> q >> h;

    std::vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    p[1] = 1;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        std::cin >> p[i];

        g[p[i]].emplace_back(i);
    }

    std::vector<std::pair<int, int>> qq;
    while (q--) {
        int t; std::cin >> t;

        if (t == 1) {
            int c, T; std::cin >> c >> T;

            qq.emplace_back(p.size(), c);
            g.emplace_back(std::vector<int>());
            g[T].emplace_back(p.size());
            p.emplace_back(T);
            a.emplace_back(0);

        } else if (t == 2) {
            int i, x; std::cin >> i >> x;

            qq.emplace_back(i, x);
        } else if (t == 3) {
            int i; std::cin >> i;

            qq.emplace_back(i, 0);
        } else {
            int i; std::cin >> i;

            qq.emplace_back(-1, i);
        }
    }

    n = p.size() - 1;

    std::vector<int> child(n + 1), hp(n + 1);

    auto Dfs = [&](auto &&self, int v, int p, int dis) -> void {
        hp[v] = p;

        for (auto to: g[v]) {
            child[v] = to;

            if (dis == h)
                self(self, to, child[p], dis);
            else
                self(self, to, p, dis + 1);
        }
    };

    Dfs(Dfs, 1, 1, 0);

    Hld hld(g);
    for (int i = 1; i <= n; ++i)
        hld.update(hp[i], i, a[i]);

    for (auto [x, y]: qq) {
        if (x == -1) {
            std::cout << hld.get(y) << '\n';
        } else {
            hld.update(hp[x], x, -a[x] + y);

            a[x] = y;
        }
    }
    return 0;
}
