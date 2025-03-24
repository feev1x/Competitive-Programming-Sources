/**
 *    author:  feev1x
 *    created: 05.03.2025 14:05:28
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<std::vector<int>> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n);
    }

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v].clear();

        int l = 0, r = 0;
        while (l < t[v << 1].size() && r < t[v << 1 | 1].size()) {
            if (t[v << 1][l] >= t[v << 1 | 1][r]) {
                t[v].emplace_back(t[v << 1 | 1][r++]);
            } else {
                t[v].emplace_back(t[v << 1][l++]);
            }
        }

        while (l < t[v << 1].size()) {
            t[v].emplace_back(t[v << 1][l++]);
        }

        while (r < t[v << 1 | 1].size()) {
            t[v].emplace_back(t[v << 1 | 1][r++]);
        }
    }

    inline void push(int v, int tl, int tr, int pos, int x) {
        t[v].emplace_back(x);

        if (tl == tr) {
            return;
        }

        int tm = tl + tr >> 1;

        if (pos <= tm) {
            push(v << 1, tl, tm, pos, x);
        } else {
            push(v << 1 | 1, tm + 1, tr, pos, x);
        }
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return std::lower_bound(t[v].begin(), t[v].end(), l) - t[v].begin();
        }

        int tm = tl + tr >> 1;

        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline void build() {
        build(1, 1, n);
    }

    inline void push(int pos, int x) {
        push(1, 1, n, pos, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1), ans(q + 1), prev(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    std::map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        prev[i] = mp[a[i]];        

        mp[a[i]] = i;
    }

    Segtree t(n);

    for (int i = 1; i <= n; ++i) {
        t.push(i, prev[i]);
    }

    t.build();

    while (q--) {
        int l, r; std::cin >> l >> r;

        std::cout << t.get(l, r) << '\n';
    }
    return 0;
}
