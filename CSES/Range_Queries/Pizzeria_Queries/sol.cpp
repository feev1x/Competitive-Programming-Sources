/**
 *    author:  feev1x
 *    created: 05.03.2025 12:47:19
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int> t_l, t_r;
    int n;

    Segtree(int _n) : n(_n) {
        t_l.resize(4 * n + 1);
        t_r.resize(4 * n + 1);
    }

    inline void update(int v, int tl, int tr, int pos, int x) {
        if (tl == tr) {
            t_l[v] = t_r[v] = x + 1;

            return;
        }
        
        int tm = tl + tr >> 1;

        if (pos <= tm) {
            update(v << 1, tl, tm, pos, x);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, x);
        }

        t_l[v] = std::min(t_l[v << 1] + tr - tm, t_l[v << 1 | 1]);
        t_r[v] = std::min(t_r[v << 1], t_r[v << 1 | 1] + tm - tl + 1);
    }

    inline int get(int v, int tl, int tr, int pos) {
        if (tr < pos) {
            return t_l[v] + (pos - tr - 1);
        }

        if (pos < tl) {
            return t_r[v] + (tl - pos - 1);
        }

        if (tl == tr) {
            return t_l[v] - 1;
        }

        int tm = tl + tr >> 1;

        return std::min(get(v << 1, tl, tm, pos), get(v << 1 | 1, tm + 1, tr, pos));
    }

    inline void update(int pos, int x) {
        update(1, 1, n, pos, x);
    }

    inline int get(int pos) {
        return get(1, 1, n, pos);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Segtree t(n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        t.update(i, a[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int i, x; std::cin >> i >> x;

            t.update(i, x);
            a[i] = x;
        } else {
            int i; std::cin >> i;

            std::cout << t.get(i) << '\n';
        }
    }
    return 0;
}
