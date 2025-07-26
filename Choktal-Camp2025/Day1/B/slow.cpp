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
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

struct Dsu {
    std::vector<int> sz, p, l, r;
    int n, ans = 1;

    Dsu(std::vector<int> _l, std::vector<int> _r) : l(_l), r(_r), n(l.size() - 1) {
        sz.assign(n + 1, 1);
        p.resize(n + 1);

        for (int i = 1; i <= n; ++i) {
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

                return;
            }

            ans = mul(ans, r[v] - l[v] + 1);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> p(n + 1), l(n + 1), r(n + 1), tin(n + 1), tout(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        std::cin >> p[i];

        g[p[i]].emplace_back(i);
        g[i].emplace_back(p[i]);
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> l[i] >> r[i];
    }

    int _t = 1;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = _t++;

        for (auto to: g[v]) {
            if (to == p) {
                continue;
            }

            self(self, to, v);
        }

        tout[v] = _t++;
    };

    Dfs(Dfs, 1, 1);

    Dsu ds(l, r);

    int m; std::cin >> m;
    while (m--) {
        int a, b, c, d; std::cin >> a >> b >> c >> d;

        if (!ds.ans) {
            std::cout << 0 << '\n';
            continue;
        }

        std::vector<int> v1, v2, temp;
        
        int u = b;
        while (true) {
            if (tin[u] <= tin[a] && tout[a] <= tout[u]) {
                break;
            }

            temp.emplace_back(u);

            u = p[u];
        }

        std::reverse(temp.begin(), temp.end());

        u = a;
        while (true) {
            v1.emplace_back(u);

            if (tin[u] <= tin[b] && tout[b] <= tout[u]) {
                break;
            }
            u = p[u];
        }

        for (auto v: temp) {
            v1.emplace_back(v);
        }

        temp.clear();

        u = d;
        while (true) {
            if (tin[u] <= tin[c] && tout[c] <= tout[u]) {
                break;
            }

            temp.emplace_back(u);
            u = p[u];
        }

        std::reverse(temp.begin(), temp.end());

        u = c;
        while (true) {
            v2.emplace_back(u);

            if (tin[u] <= tin[d] && tout[d] <= tout[u]) {
                break;
            }
            u = p[u];
        }

        for (auto v: temp) {
            v2.emplace_back(v);
        }

        temp.clear();

        for (int i = 0; i < v1.size(); ++i) {
            ds.unite(v1[i], v2[i]);
        }

        std::cout << ds.ans << '\n';
    }
    return 0;
}

