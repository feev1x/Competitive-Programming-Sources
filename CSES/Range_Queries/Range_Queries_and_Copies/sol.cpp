/**
 *    author:  feev1x
 *    created: 06.03.2025 09:25:10
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<std::vector<int64_t>> t;
    std::vector<std::map<int, std::vector<std::pair<int, int>>>> mp;
    std::vector<int64_t> a;
    std::vector<int> c_of, t_ar;
    int n, q;

    inline void build(int v, int tl, int tr) {
        mp[v][1].emplace_back(q, 0);

        if (tl == tr) {
            t[v].emplace_back(a[tl]);

            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v].emplace_back(t[v << 1][0] + t[v << 1 | 1][0]);
    }

    Segtree(int _n, std::vector<int64_t> _a) : n(_n), a(_a), q(0) {
        t.resize(4 * n + 1);
        mp.resize(4 * n + 1);
        c_of.resize(2);
        t_ar.resize(2);

        build(1, 1, n);
    }

    inline int64_t get_v(int v, int k) {
        if (mp[v].count(k)) {
            return t[v][mp[v][k].back().second];
        }

        if (mp[v].count(c_of[k]) && mp[v][c_of[k]][0].first <= t_ar[k]) {
            auto it = --std::upper_bound(mp[v][c_of[k]].begin(), mp[v][c_of[k]].end(), std::make_pair(t_ar[k], -1));

            return t[v][it->second]; 
        }

        return t[v][0];
    }

    inline void update(int v, int tl, int tr, int k, int pos, int x) {
        if (tl == tr) {
            mp[v][k].emplace_back(q, t[v].size());
            t[v].emplace_back(x);

            return;
        }

        int tm = tl + tr >> 1;

        if (pos <= tm) {
            update(v << 1, tl, tm, k, pos, x);
        } else {
            update(v << 1 | 1, tm + 1, tr, k, pos, x);
        }

        mp[v][k].emplace_back(q, t[v].size());
        t[v].emplace_back(get_v(v << 1, k) + get_v(v << 1 | 1, k));
    }

    inline int64_t get(int v, int tl, int tr, int k, int l, int r) {
        if (l > tr || tl > r) {
            return 0ll;
        }

        if (l <= tl && tr <= r) {
            return get_v(v, k);
        }

        int tm = tl + tr >> 1;

        return get(v << 1, tl, tm, k, l, r) + get(v << 1 | 1, tm + 1, tr, k, l, r);
    }

    inline void copy(int k) {
        c_of.emplace_back(k);
        t_ar.emplace_back(++q);
    }

    inline void update(int k, int pos, int x) {
        q++;

        update(1, 1, n, k, pos, x);
    }

    inline int64_t get(int k, int l, int r) {
        return get(1, 1, n, k, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    Segtree t(n, a);

    while (q--) {
        int type, k; std::cin >> type >> k;

        if (type == 1) {
            int pos, x; std::cin >> pos >> x;

            t.update(k, pos, x);
        } else if (type == 2) {
            int l, r; std::cin >> l >> r;

            std::cout << t.get(k, l, r) << '\n';
        } else {
            t.copy(k);
        }
    }
    return 0;
}
