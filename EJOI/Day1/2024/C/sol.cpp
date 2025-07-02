/**
 *    author:  feev1x
 *    created: 25.04.2025 11:54:03
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<std::pair<int, int>> e;
    std::vector<int> a;
    std::vector<std::array<int, 51>> t;
    int n;

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v][e[a[tl]].first] = e[a[tl]].second;

            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        for (int i = 1; i <= 50; ++i) {
            t[v][i] = t[v << 1 | 1][t[v << 1][i]];
        }
    }

    Segtree(std::vector<int> _a, std::vector<std::pair<int, int>> _e) : a(_a), e(_e), n(a.size() - 1) {
        std::array<int, 51> arr;

        std::iota(arr.begin(), arr.end(), 0);

        t.assign(4 * n + 1, arr);

        build(1, 1, n);
    }

    inline void update(int v, int tl, int tr, int i, int k) {
        if (tl == tr) {
            t[v][e[a[tl]].first] = e[a[tl]].first;

            a[tl] = k;

            t[v][e[a[tl]].first] = e[a[tl]].second;

            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm) {
            update(v << 1, tl, tm, i, k);
        } else {
            update(v << 1 | 1, tm + 1, tr, i, k);
        }

        for (int i = 1; i <= 50; ++i) {
            t[v][i] = t[v << 1 | 1][t[v << 1][i]];
        }
    }

    inline int get(int v, int tl, int tr, int l, int r, int s) {
        if (tl > r || l > tr) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return t[v][s];
        }

        int tm = tl + tr >> 1;

        int got = get(v << 1, tl, tm, l, r, s);

        if (got) {
            s = got;
        }

        got = get(v << 1 | 1, tm + 1, tr, l, r, s);

        if (got) {
            s = got;
        }

        return s;
    }

    inline void update(int i, int k) {
        update(1, 1, n, i, k);
    }

    inline int get(int l, int r, int s) {
        return get(1, 1, n, l, r, s);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::pair<int, int>> e(1);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        e.emplace_back(u, v);
    }

    int _t; std::cin >> _t;

    std::vector<int> a(_t + 1);
    for (int i = 1; i <= _t; ++i) {
        std::cin >> a[i];
    }

    Segtree t(a, e);

    int q; std::cin >> q;
    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int l, r, s; std::cin >> l >> r >> s;

            std::cout << t.get(l, r, s) << '\n';
        } else {
            int i, k; std::cin >> i >> k;

            t.update(i, k);
        }
    }
    return 0;
}
