#include <bits/stdc++.h>

struct Dsu {
    std::vector<int> p, sz;
    std::stack<std::pair<int, int>> stk;
    int n;

    Dsu() {}
    Dsu(int n) : n(n) {
        p.resize(n + 1);
        sz.assign(n + 1, 1);

        std::iota(p.begin(), p.end(), 0);
    }

    inline int get(int v) {
        return v == p[v] ? v : get(p[v]);
    }

    inline void rollback(int k) {
        while (k--) {
            auto [u, v] = stk.top();

            p[u] = u;
            sz[v] -= sz[u];
        }
    }

    inline void unite(int u, int v) {
        u = get(u), v = get(v);

        if (u != v) {
            if (sz[u] > sz[v]) {
                std::swap(u, v);
            }

            stk.emplace(u, v);
            p[u] = v;
            sz[v] += sz[u];
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<int> ar(1);
    std::vector<std::array<int, 4>> e(m);

    int mn = 2 * m + 5, nw = 0;

    bool bamb = true;
    for (auto &[a, b, c, d]: e) {
        std::cin >> a >> b >> c >> d;

        ar.emplace_back(c);
        ar.emplace_back(d);

        bamb = bamb && a == nw + 1 && b == nw + 2;

        nw++;
    }

    std::sort(ar.begin(), ar.end());
    ar.erase(unique(ar.begin(), ar.end()), ar.end());

    for (auto &[a, b, c, d]: e) {
        c = std::lower_bound(ar.begin(), ar.end(), c) - ar.begin();
        d = std::lower_bound(ar.begin(), ar.end(), d) - ar.begin();

        mn = std::min(mn, d);
    }

    int q; std::cin >> q;
    std::vector<std::array<int, 4>> qq(q);
    for (auto &[x, y, l, r]: qq) {
        std::cin >> x >> y >> l >> r;

        l = std::lower_bound(ar.begin(), ar.end(), l) - ar.begin();
        r = std::upper_bound(ar.begin(), ar.end(), r) - ar.begin() - 1;
    }

    if (std::max({n, m, q}) <= 3000) {
        std::vector<Dsu> dsu(ar.size(), Dsu(n));

        for (int i = 0; i < ar.size(); ++i) {
            for (auto [a, b, c, d]: e) {
                if (c <= i && i <= d) {
                    dsu[i].unite(a, b);
                }
            }
        }

        for (auto [x, y, l, r]: qq) {
            int res = 0;

            for (int i = l; i <= r; ++i) {
                res += dsu[i].get(x) == dsu[i].get(y);
            }

            std::cout << res << '\n';
        }
    } else if (m == n - 1 && bamb) {
    }

    return 0;
}
