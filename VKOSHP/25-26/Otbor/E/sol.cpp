#include <bits/stdc++.h>

inline void chmax(int &a, int b) {
    if (a < b)
        a = b;
}

struct Node {
    int pref = 0, suff = 0, max = 0, pval = 0, sval = 0, sz = 0;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = {1, 1, 1, 0, 0, 1};
            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v] = {1, 1, 1, 0, 0, tr - tl + 1};
    }

    Segtree(int _n) : n(_n) {
        t.resize(4 * n);

        build(1, 1, n);
    }

    inline Node comb(Node a, Node b) {
        Node res;

        chmax(res.max, std::max(a.max, b.max));

        if (a.sval - b.pval == 1)
            chmax(res.max, std::min(b.pref, a.suff - 1) * 2 + 1);
        else if (a.sval - b.pval == -1)
            chmax(res.max, std::min(b.pref - 1, a.suff) * 2 + 1);

        res.pval = a.pval;
        res.sz = a.sz + b.sz;
        res.sval = b.sval;
        res.pref = a.pref;
        res.suff = b.suff;

        if (a.sval == b.sval - b.sz && b.sz == b.suff)
            res.suff = b.sz + a.suff;

        if (b.pval == a.pval - a.sz && a.sz == a.pref)
            res.pref = a.sz + b.pref;

        return res;
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = {1, 1, 1, x, x, 1};
            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);

    }

    inline int get() {
        return t[1].max;
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    Segtree t(n + 1);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        t.update(i, a[i]);
    }

    std::cout << t.get() << '\n';

    int q; std::cin >> q;
    while (q--) {
        int i, x; std::cin >> i >> x;

        t.update(i, x);
        
        std::cout << t.get() << '\n';
    }
}
