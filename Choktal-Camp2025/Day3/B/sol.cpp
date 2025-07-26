/**
 *    author:  feev1x
 *    created: 03.07.2025 11:17:59
**/
#include <bits/stdc++.h>

struct Segtree {
    const int INF = 2e9;

    std::vector<int> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.assign(4 * n + 1, INF);
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = std::min(t[v], x);

            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = std::min(t[v << 1], t[v << 1 | 1]);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return INF;

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;

        return std::min(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
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
        int n, k; std::cin >> n >> k;

        std::vector<int> l(k), m(k), r(k), idx(k);
        for (int i = 0; i < k; ++i)
            std::cin >> l[i] >> m[i] >> r[i], idx[i] = i;

        std::sort(idx.begin(), idx.end(), [&](int i, int j) {
            if (l[i] == l[j])
                return r[i] < r[j];

            return l[i] < l[j];
        });

        Segtree t(n), t2(n);
        std::vector<bool> dp(k);
        std::set<std::pair<int, int>> st;

        bool flag = false;
        for (auto i: idx) {
            if (l[i] == 1 || t.get(std::max(1, l[i] - 1), std::max(1, m[i] - 1)) == 1 || t2.get(m[i], r[i]) < l[i]) {
                if (r[i] == n) {
                    flag = true;
                    break;
                }

                dp[i] = true;

                t.update(r[i], 1);
                t2.update(r[i], m[i]);
            }
        }

        std::cout << (flag ? "YES\n" : "NO\n");
    }
    
    return 0;
}
