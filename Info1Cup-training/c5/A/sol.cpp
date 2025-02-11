/**
 *    author:  feev1x
 *    created: 03.02.2025 09:03:48
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(n * 4 + 5);
    }

    inline void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            t[v] = val;

            return;
        }

        int tm = tl + tr >> 1;

        if (pos <= tm) {
            update(v << 1, tl, tm, pos, val);
        } else {
            update(v << 1 | 1, tm + 1, tr, pos, val);
        }

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return 0;
        }
    
        if (l <= tl && tr <= r) {
            return t[v];
        }

        int tm = tl + tr >> 1;

        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void modify(int pos, int val) {
        update(1, 1, n, pos, val);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;
        
        std::vector<int> a(n + 1), l(n + 1), r(n + 1), mp(n + 1), ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }

        auto b = a;

        std::sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        for (int i = 1; i <= n; ++i) {
            a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (l[a[i]] == 0) {
                l[a[i]] = i;
                r[a[i]] = i;
            } else {
                r[a[i]] = i;
            }

            mp[a[i]]++;

            ans[a[i]] = mp[a[i]];
        }

        Segtree t(n);
        for (int i = n; i >= 1; --i) {
            if (r[a[i]] == i) {
                ans[a[i]] = std::max(ans[a[i]], mp[a[i]] + t.get(a[i], n));
            }

            if (l[a[i]] == i) {
                t.modify(a[i], ans[a[i]]);
            }
        }

        std::cout << *max_element(ans.begin(), ans.end()) << '\n';
    }
    return 0;
}
