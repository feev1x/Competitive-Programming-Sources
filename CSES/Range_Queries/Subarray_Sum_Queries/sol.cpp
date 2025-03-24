/**
 *    author:  feev1x
 *    created: 05.03.2025 13:20:06
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int64_t> t, pref, suff, sum;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
        pref.resize(4 * n + 1);
        suff.resize(4 * n + 1);
        sum.resize(4 * n + 1);
    }

    inline void update(int v, int tl, int tr, int pos, int x) {
        if (tl == tr) {
            t[v] = pref[v] = suff[v] = std::max(0, x);
            sum[v] = x;

            return;
        }

        int tm = tl + tr >> 1;

        if (pos <= tm) {
            update(v << 1, tl, tm, pos, x);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, x);
        }

        t[v] = std::max({t[v << 1], t[v << 1 | 1], suff[v << 1] + pref[v << 1 | 1], (int64_t)0});
        sum[v] = sum[v << 1] + sum[v << 1 | 1];
        pref[v] = std::max({(int64_t)0, pref[v << 1], sum[v << 1] + pref[v << 1 | 1]});
        suff[v] = std::max({(int64_t)0, suff[v << 1 | 1], suff[v << 1] + sum[v << 1 | 1]});
    }

    inline void update(int pos, int x) {
        update(1, 1, n, pos, x);
    }

    inline int64_t get() {
        return t[1];
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    Segtree t(n);
    std::vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        t.update(i, a[i]);
    }

    while (m--) {
        int i, x; std::cin >> i >> x;

        t.update(i, x);

        std::cout << t.get() << '\n';
    }
    return 0;
}
