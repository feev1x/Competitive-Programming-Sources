/**
 *    author:  feev1x
 *    created: 01.07.2025 12:36:50
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

struct Dsu1 {
    std::vector<int> sz, p;
    int n;

    Dsu1() {}

    Dsu1(int _n) : n(_n) {
        sz.assign(n, 1);
        p.resize(n);

        std::iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : p[v] = get(p[v]);
    }

    inline bool unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v])
                std::swap(u, v);

            p[u] = v;
            sz[v] += sz[u];

            return true;
        }

        return false;
    }
};

struct Dsu {
    std::vector<int> sz, p, l, r;
    int n, ans = 1;

    Dsu() {}

    Dsu(std::vector<int> _l, std::vector<int> _r) : l(_l), r(_r), n(l.size()) {
        sz.assign(n, 1);
        p.resize(n);

        for (int i = 0; i < n; ++i) {
            ans = mul(ans, r[i] - l[i] + 1);
        }

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

            ans = divide(ans, r[u] - l[u] + 1);
            ans = divide(ans, r[v] - l[v] + 1);

            l[v] = std::max(l[u], l[v]);
            r[v] = std::min(r[u], r[v]);

            p[u] = v;
            sz[v] += sz[u];
            if (l[v] > r[v]) {
                ans = 0;
            }

            ans = mul(ans, r[v] - l[v] + 1);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::vector<int> par(n), l(n), r(n), tin(n), tout(n), d(n);
    std::vector<std::array<int, 20>> anc(n);
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; ++i) {
        std::cin >> par[i]; par[i]--;

        g[par[i]].emplace_back(i);
        g[i].emplace_back(par[i]);
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> l[i] >> r[i];
    }

    int _t = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = ++_t;
        anc[v][0] = p;
        d[v] = d[p] + 1;

        for (int i = 1; i < 20; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }

        tout[v] = ++_t;
    };

    Dfs(Dfs, 0, 0);

    int ds = 0;
    auto Lca = [&](int u, int v) {
        ds = 0;

        if (tin[u] <= tin[v] && tout[v] <= tout[u])
            return u;

        for (int i = 19; i >= 0; --i) {
            int nx = anc[u][i];

            if (tin[nx] > tin[v] || tout[v] > tout[nx])
                u = nx, ds += 1 << i;
        }

        ds++;
        return anc[u][0];
    };

    auto Jump = [&](int u, int v, int lca, int x) {
        if (d[u] - d[lca] >= x) {
            for (int i = 0; i < 19; ++i) {
                if (x >> i & 1) {
                    u = anc[u][i];
                }
            }

            return u;
        }

        x -= (d[u] - d[lca]);

        x = (d[v] - d[lca]) - x;

        for (int i = 0; i < 19; ++i) {
            if (x >> i & 1) {
                v = anc[v][i];
            }
        }

        return v;
    };

    std::vector<Dsu1> dsu(20);

    Dsu ds0(l, r);

    for (int i = 1; i < 20; ++i)
        dsu[i] = Dsu1(2 * n);

    auto Add = [&](auto &&self, int u, int v, int k) -> void {
        if (k == 0) {
            ds0.unite(u % n, v % n);

            return;
        }

        if (dsu[k].unite(u, v)) {
            if (u / n == v / n) {
                self(self, u, v, k - 1);
                self(self, anc[u % n][k - 1] + (u / n) * n, anc[v % n][k - 1] + (v / n) * n, k - 1);
            } else {
                self(self, u, anc[v % n][k - 1] + (v / n) * n, k - 1);
                self(self, anc[u % n][k - 1] + (u / n) * n, v, k - 1);
            }
        }
    };

    int q; std::cin >> q;
    while (q--) {
        int _a, _b, _c, _d; std::cin >> _a >> _b >> _c >> _d;
        _a--, _b--, _c--, _d--;

        if (n == 1) {
            std::cout << r[0] - l[0] + 1 << '\n';

            continue;
        }

        int lca = Lca(_a, _b);

        int dl = ds;

        int lca1 = Lca(_c, _d);

        int dl1 = ds;

        if (dl > dl1) {
            int jp = Jump(_a, _b, lca, dl1);

            int jp1 = Jump(_d, _c, lca1, d[_d] - d[lca1] - dl + dl1);

            int k;
            for (k = 19; k >= 0; --k)
                if ((1 << k) <= dl - dl1 + 1)
                    break;


            int ip = Jump(jp, _b, lca, dl - dl1 + 1 - (1 << k));
            int ip1 = Jump(jp1, _c, lca1, dl - dl1 + 1 - (1 << k));

            Add(Add, ip + n, jp1, k);
            Add(Add, jp, ip1 + n, k);
        } else {
            int jp = Jump(_c, _d, lca1, dl);

            int jp1 = Jump(_b, _a, lca, d[_b] - d[lca] - dl1 + dl);

            int k;
            for (k = 19; k >= 0; --k)
                if ((1 << k) <= dl1 - dl + 1)
                    break;

            int ip = Jump(jp, _d, lca1, dl1 - dl + 1 - (1 << k));
            int ip1 = Jump(jp1, _a, lca, dl1 - dl + 1 - (1 << k));

            Add(Add, ip + n, jp1, k);
            Add(Add, jp, ip1 + n, k);
        }

        if (std::min(dl, dl1)) {
            int sz = std::min(dl, dl1);

            int k;
            for (k = 19; k >= 0; --k)
                if ((1 << k) <= sz)
                    break;
            
            Add(Add, _a, _c, k);

            int jp = Jump(_a, _b, lca, sz - (1 << k));
            int jp1 = Jump(_c, _d, lca1, sz - (1 << k));

            Add(Add, jp, jp1, k);
        }

        if (std::min(d[_b] - d[lca], d[_d] - d[lca1])) {
            int sz = std::min(d[_b] - d[lca], d[_d] - d[lca1]);

            int k;
            for (k = 19; k >= 0; --k)
                if ((1 << k) <= sz)
                    break;

            Add(Add, _b, _d, k);

            int jp = Jump(_b, _a, lca, sz - (1 << k));
            int jp1 = Jump(_d, _c, lca1, sz - (1 << k));

            Add(Add, jp, jp1, k);
        }

        std::cout << ds0.ans << '\n';
    }
    return 0;
}
