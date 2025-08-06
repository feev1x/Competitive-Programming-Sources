/**
 *    author:  feev1x
 *    created: 02.08.2025 16:14:52
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree (int _n) : n(_n) {
        t.resize(4 * n + 1);
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = std::max(t[v], x);
            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return 0;

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;

        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
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
    
    int n; std::cin >> n;    

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    std::vector<std::vector<std::pair<int, int>>> qq(n + 1);

    int q; std::cin >> q;

    std::vector<std::array<int, 3>> ans(q + 1, {-1, -1, -1});
    for (int i = 1; i <= q; ++i) {
        int l, r; std::cin >> l >> r;

        qq[l].emplace_back(r, i);
    }


    Segtree t(n + 1);
    std::vector<int> tr(n + 1, n + 1);
    std::vector<std::vector<int>> sl(n + 1, {n + 1}), pr(n + 1, {n + 1});
    auto Pr = [&](int i, int x) {
        int l = 0, r = (int)pr[i].size() - 1, ans = 0;

        while (l <= r) {
            int m = l + r >> 1;

            if (pr[i][m] > x)
                l = m + 1, ans = m;
            else
                r = m - 1;
        }

        return pr[i][ans];
    };

    auto Sl = [&](int i, int x) {
        int l = 0, r = (int)sl[i].size() - 1, ans = 0;

        while (l <= r) {
            int m = l + r >> 1;

            if (sl[i][m] > x)
                l = m + 1, ans = m;
            else
                r = m - 1;
        }

        return sl[i][ans];
    };

    for (int l = n; l >= 1; --l) {
        sl[a[l]].emplace_back(l);

        int pp = n + 1;
        for (int i = 1; i * i <= a[l]; ++i)
            if (a[l] % i == 0) {
                int j = a[l] / i;

                if (i != a[l]) {
                    tr[a[l]] = std::min(tr[a[l]], pr[i].back());
                    pp = std::min(pp, sl[i].back());
                }

                if (j != a[l]) {
                    tr[a[l]] = std::min(tr[a[l]], pr[j].back());
                    pp = std::min(pp, sl[j].back());
                }
            }

        pr[a[l]].emplace_back(pp);
        t.update(tr[a[l]], a[l]);

        for (auto [r, i]: qq[l]) {
            int vl = t.get(l, r);

            if (vl != 0) {
                ans[i][0] = sl[vl].back();

                while (ans[i][0] > n);

                int vl2 = -1;
                for (int j = 1; j * j <= vl; ++j) {
                    if (vl % j == 0) {
                        int k = vl / j;

                        if (k != vl && Pr(k, ans[i][0]) <= r)
                            vl2 = std::max(vl2, k);

                        if (j != vl && Pr(j, ans[i][0]) <= r)
                            vl2 = std::max(vl2, j);
                    }
                }

                ans[i][1] = Sl(vl2, ans[i][0]);

                while (ans[i][1] > n);

                int vl3 = -1;
                for (int j = 1; j * j <= vl2; ++j) {
                    if (vl2 % j == 0) {
                        int k = vl2 / j;

                        if (k != vl2 && Sl(k, ans[i][1]) <= r)
                            vl3 = std::max(vl3, k);

                        if (j != vl2 && Sl(j, ans[i][1]) <= r)
                            vl3 = std::max(vl3, j);
                    }
                }

                ans[i][2] = Sl(vl3, ans[i][1]);

                while (ans[i][2] > n);
            }
        }
    }

    for (int i = 1; i <= q; ++i)
        if (ans[i][0] == -1)
            std::cout << "-1\n";
        else
            std::cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';

    return 0;
}
