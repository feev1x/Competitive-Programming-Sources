/**
 *    author:  feev1x
 *    created: 22.07.2025 14:00:50
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int> t, suff, pref;
    int n, sum;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
        suff.resize(4 * n + 1);
        pref.resize(4 * n + 1);
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            pref[v] = suff[v] = t[v] = x;

            return;
        }

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = t[v << 1] + t[v << 1 | 1];
        pref[v] = std::max(pref[v << 1], t[v << 1] + pref[v << 1 | 1]);
        suff[v] = std::max(suff[v << 1] + t[v << 1 | 1], suff[v << 1 | 1]);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return 0;

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;

        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline int sfx(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return 0;
        
        if (l <= tl && tr <= r) {
            sum += t[v];

            return sum - t[v] + suff[v];
        }

        int tm = tl + tr >> 1;

        int right = sfx(v << 1 | 1, tm + 1, tr, l, r);
        int left = sfx(v << 1, tl, tm, l, r);
        return std::max(right, left);
    }

    inline int pfx(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return 0;
        
        if (l <= tl && tr <= r) {
            sum += t[v];

            return sum - t[v] + pref[v];
        }

        int tm = tl + tr >> 1;

        int left = pfx(v << 1, tl, tm, l, r);
        int right = pfx(v << 1 | 1, tm + 1, tr, l, r);

        return std::max(left, right);
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    inline int get(int l, int r) {
        if (l > r)
            return 0;

        return get(1, 1, n, l, r);
    }

    inline int sfx(int l, int r) {
        if (l > r)
            return 0;

        sum = 0;

        return std::max(0, sfx(1, 1, n, l, r));
    }

    inline int pfx(int l, int r) {
        if (l > r) 
            return 0;

        sum = 0;

        return std::max(0, pfx(1, 1, n, l, r));
    }
};

struct Sptable {
    std::vector<std::vector<int>> sp;
    std::vector<int> lg;
    int n;

    Sptable(std::vector<int> a) : n(a.size() - 1) {
        lg.resize(n + 1);

        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;

        sp.resize(lg[n] + 1, std::vector<int>(n + 1));

        sp[0] = a;

        for (int i = 1; i <= lg[n]; ++i)
            for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                sp[i][j] = std::min(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
    }

    inline int get(int l, int r) {
        int i = lg[r - l + 1];

        return std::min(sp[i][l], sp[i][r - (1 << i) + 1]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        Segtree t(n);
        std::vector<int> a(n + 1);
        std::vector<std::vector<int>> pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            pos[a[i]].emplace_back(i);

            t.update(i, 1);
        }

        int res = 0;
        Sptable sp(a);
        for (int med = 1; med <= n; ++med) {
            for (auto i: pos[med]) {
                int l = 1, r = med - 1, ans = med;

                while (l <= r) {
                    int m = l + r >> 1;

                    bool flag = false;
                    {
                        int l = 1, r = i - 1, ans = -1;
                        
                        while (l <= r) {
                            int mid = l + r >> 1;

                            if (sp.get(mid, i - 1) > m)
                                r = mid - 1;
                            else
                                l = mid + 1, ans = mid;
                        }

//                        if (med == 4)
//                            std::cout << ans << ' ' << i << ' ' << t.pfx(i + 1, n) << '\n';

                        if (ans != -1 && t.get(ans, i) + t.sfx(1, ans - 1) + t.pfx(i + 1, n) >= 0)
                            flag = true;
                    }

                    if (!flag) {
                        int l = i + 1, r = n, ans = -1;
                        
                        while (l <= r) {
                            int mid = l + r >> 1;

                            if (sp.get(i + 1, mid) > m)
                                l = mid + 1;
                            else
                                r = mid - 1, ans = mid;
                        }

                        if (ans != -1 && t.get(i, ans) + t.sfx(1, i - 1) + t.pfx(ans + 1, n) >= 0)
                            flag = true;
                    }

                    if (flag)
                        r = m - 1, ans = m;
                    else
                        l = m + 1;
                }

                res = std::max(res, med - ans);
            }

            for (auto i: pos[med])
                t.update(i, -1);
        }

        std::cout << res << '\n';
    }

    return 0;
}
