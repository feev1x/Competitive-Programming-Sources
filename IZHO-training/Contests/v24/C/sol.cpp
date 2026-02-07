#include <bits/stdc++.h>

struct Node {
    int mx, pref, suff, sum;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    Segtree(int n) : n(n) {
        t.resize(4 * n);
    }

    inline Node comb(Node a, Node b) {
        Node res;

        res.sum = a.sum + b.sum;
        res.pref = std::max(a.pref, a.sum + b.pref);
        res.suff = std::max(a.suff + b.sum, b.suff);
        res.mx = std::max({a.mx, b.mx, a.suff + b.pref});

        return res;
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = {x, x, x, x};
            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm) {
            update(v << 1, tl, tm, i, x);
        } else {
            update(v << 1 | 1, tm + 1, tr, i, x);
        }

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }

    inline Node get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr) {
            return {0, 0, 0, 0};
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        int tm = tl + tr >> 1;
        return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    inline Node get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q; std::cin >> n >> q;

    Segtree t(n);
    std::vector<int> a(n + 1);
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        t.update(i, a[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int p; std::cin >> p;

            a[p] = -a[p];
            t.update(p, a[p]);
        } else {
            int l, r; std::cin >> l >> r;

            auto got = t.get(l, r);

            std::cout << r - l + 1 - got.mx + got.sum << '\n';
        }
    }

    return 0;
}
