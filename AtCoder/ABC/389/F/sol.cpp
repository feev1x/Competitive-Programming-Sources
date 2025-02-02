/**
 *    author:  feev1x
 *    created: 29.01.2025 20:12:03
**/
#include <bits/stdc++.h>

constexpr int N = 5e5;

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(n * 4 + 5);
    }

    inline void update(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            t[v]++;

            return;
        }

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r);
        update(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline int get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        }

        int tm = tl + tr >> 1;
        if (pos <= tm) {
            return t[v] + get(v << 1, tl, tm, pos);
        }

        return t[v] + get(v << 1 | 1, tm + 1, tr, pos);
    }

    inline void modify(int l, int r) {
        if (l > r) {
            return;
        }

        update(1, 1, n, l, r);
    }

    inline int get(int pos) {
        return get(1, 1, n, pos) + pos;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    Segtree t(N);
    for (int i = 0; i < n; ++i) {
        int L, R; std::cin >> L >> R;

        int left = 0, right = 0;

        int l = 1, r = 5e5;
        while (l <= r) {
            int m = l + r >> 1;

            if (t.get(m) >= L) {
                r = m - 1;
                left = m;
            } else {
                l = m + 1;
            }
        }


        l = 1, r = 5e5;
        while (l <= r) {
            int m = l + r >> 1;

            if (t.get(m) > R) {
                r = m - 1;
            } else {
                l = m + 1;
                right = m;
            }
        }

        t.modify(left, right);
    }

    int q; std::cin >> q;
    while (q--) {
        int x; std::cin >> x;

        std::cout << t.get(x) << '\n';
    }
    return 0;
}
