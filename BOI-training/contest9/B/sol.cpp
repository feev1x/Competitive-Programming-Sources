/**
 *    author:  feev1x
 *    created: 22.09.2025 16:58:12
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


struct Hld {
    struct Segtree {
        std::vector<int> t, psh;
        int n;

        Segtree () {}
        Segtree(int _n) : n(_n) {
            t.resize(4 * n + 1);
            psh.resize(4 * n + 1);
        }

        inline void push(int v, int tl, int tr, int tm) {
            if (psh[v]) {
                psh[v << 1] = psh[v << 1] ^ psh[v];
                psh[v << 1 | 1] = psh[v << 1 | 1] ^ psh[v];

                t[v << 1] = (tm - tl + 1) - t[v << 1];
                t[v << 1 | 1] = (tr - tm) - t[v << 1 | 1];

                psh[v] = 0;
            }

        }
        
        inline void update(int v, int tl, int tr, int l, int r) {
            if (l > tr || tl > r)
                return;

            if (l <= tl && tr <= r) {
                t[v] = (tr - tl + 1) - t[v];

                psh[v] = !psh[v];
                return;
            }

            int tm = tl + tr >> 1;
            push(v, tl, tr, tm);
            update(v << 1, tl, tm, l, r);
            update(v << 1 | 1, tm + 1, tr, l, r);

            t[v] = t[v << 1] + t[v << 1 | 1];
        }

        inline int get(int v, int tl, int tr, int l, int r) {
            if (l > tr || tl > r)
                return 0;

            if (l <= tl && tr <= r)
                return t[v];


            int tm = tl + tr >> 1;

            push(v, tl, tr, tm);
            return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
        }
    };

    std::vector<bool> rev;
    std::vector<int> tin, heavy, sz, head, par, cnt, hsz;
    std::vector<std::vector<int>> g;
    int n, root, timer, res;
    Segtree t;

    inline void dfs(int v, int p) {
        sz[v] = 1;

        par[v] = p;
        for (auto to: g[v]) {
            if (to == p)
                continue;

            dfs(to, v);

            sz[v] += sz[to];
        }
    }

    inline void dec(int v, int p) {
        hsz[head[v]]++;

        for (auto to: g[v])
            if (to != p && sz[to] > heavy[v])
                heavy[v] = to;

        tin[v] = ++timer;

        head[heavy[v]] = head[v];
        if (heavy[v])
            dec(heavy[v], v);

        for (auto to: g[v])
            if (to != p && to != heavy[v])
                dec(to, v);
    }

    Hld(std::vector<std::vector<int>> _g) : g(_g), n(g.size() - 1) {
        res = 0;
        tin.resize(n + 1);
        heavy.resize(n + 1);
        sz.resize(n + 1);
        head.resize(n + 1);
        par.resize(n + 1);
        rev.resize(n + 1);
        cnt.resize(n + 1);
        hsz.resize(n + 1);

        for (int i = 1; i <= n; ++i) {
            if (g[i].size() > 1)
                root = i;

            head[i] = i;
        }

        timer = 0;
        t = Segtree(n);
        dfs(root, root);
        dec(root, root);
    }

    inline int get() {
        return t.t[1];
    }

    inline int get(int v) {
        v = head[v];

        if (rev[v])
            return hsz[v] - cnt[v];

        return cnt[v];
    }

    inline void solo_upd(int v) {
        res -= get(v);
        t.update(1, 1, n, tin[v], tin[v]);
        cnt[head[v]]++;
        res += get(v);
    }

    inline void update(int v) {
        res -= get(v);
        t.update(1, 1, n, tin[head[v]], tin[v]);
        cnt[head[v]] = t.get(1, 1, n, tin[head[v]], tin[head[v]] + hsz[head[v]] - 1);
        res += get(v);

        if (head[v] == root)
            return;

        v = par[head[v]];
        while (true) {
            res -= get(v);
            rev[head[v]] = !rev[head[v]];
            res += get(v);

            if (head[v] == root || !head[v]) 
                break;

            v = par[head[v]];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;    

    std::vector<std::vector<int>> adj(n + 1);
    for (int i = 1; i < n; ++i) 
{
        int u, v; std::cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    if (n <= 2) {
        while (q--) {
            int d; std::cin >> d;

            auto g = adj;

            n += d;
            g.resize(n + 1);
            for (int i = 1; i <= d; ++i) {
                int u; std::cin >> u;

                g[u].emplace_back(n - d + i);
                g[n - d + i].emplace_back(u);
            }

            std::vector<int> cnt(n + 1);
            int res = 0;
            auto Dfs = [&](auto &&self, int v, int p) -> void {
                if (g[v].size() == 1) {
                    cnt[v] = 1;
                    return;
                }

                for (auto to: g[v]) {
                    if (to == p)
                        continue;

                    self(self, to, v);
                    cnt[v] += cnt[to];

                    res += 2;
                    if (cnt[to] & 1)
                        res--;
                }
            };

            if (n == 2) {
                std::cout << "1\n";
                continue;
            }

            int root = -1;
            for (int i = 1; i <= n; ++i)
                if (g[i].size() > 1)
                    root = i;

            assert(root != -1);

            Dfs(Dfs, root, root);
            if (cnt[root] & 1)
                std::cout << "-1\n";
            else
                std::cout << res << '\n';

            n -= d;
        }
    } else {
        std::vector<bool> cnt(n + 1);
        std::vector<int> par(n + 1), tin(n + 1), tout(n + 1);

        int res = 0, timer = 0;
        auto Dfs = [&](auto &&self, int v, int p) -> void {
            par[v] = p;

            if (adj[v].size() == 1) {
                cnt[v] = 1;
                return;
            }

            for (auto to: adj[v]) {
                if (to == p)
                    continue;

                self(self, to, v);
                cnt[v] = cnt[v] ^ cnt[to];

                res += cnt[to];
            }
        };

        int root = -1;
        for (int i = 1; i <= n; ++i)
            if (adj[i].size() > 1)
                root = i;

        assert(root != -1);
        
        Hld hld(adj);

        Dfs(Dfs, root, root);
        for (int i = 1; i <= n; ++i)
            if (cnt[i])
                hld.solo_upd(i);

        while (q--) {
            int d; std::cin >> d;

            std::vector<int> add(d);
            std::unordered_map<int, bool> upd;

            int lf = 0;
            for (auto &u: add)
                std::cin >> u, upd[u] = !upd[u];

            for (auto [key, val]: upd) {
                int u = key;

                lf += adj[u].size() == 1;
                if ((adj[u].size() > 1) == val)
                    hld.update(u);
            }

            if (((d - lf) + cnt[root]) & 1)
                std::cout << "-1\n";
            else
                std::cout << (n + d - 1) * 2 - hld.get() - d << '\n';

            for (auto [key, val]: upd) {
                int u = key;

                if ((adj[u].size() > 1) == val)
                    hld.update(u);
            }
        }
    }
    return 0;
}
