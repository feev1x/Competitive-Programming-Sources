/**
 *    author:  feev1x
 *    created: 27.07.2025 21:18:41
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n + 1);
        std::vector<std::vector<int>> pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];

            pos[a[i]].emplace_back(i);
        }

        int res = -1, L = -1, R = -1;
        int l = 1, r = n;
        while (l <= r) {
            int m = l + r >> 1;

            Segtree t(n);
            for (int i = 1; i <= n; ++i)
                if (a[i] < m)
                    t.update(i, -1);
                else
                    t.update(i, 1);

            bool flag = false;
            for (int lf = 1; lf + k - 1 <= n; ++lf) {
                int i = lf + k;

                int val = t.pfx(i, n), got = t.get(lf, i - 1);

                if (got + val >= 0) {
                    flag = true;

                    for (int rg = i - 1; rg <= n; ++rg) {
                        if (got >= 0) {
                            res = m, L = lf, R = rg;

                            break;
                        }

                        if (a[rg + 1] < m)
                            got--;
                        else
                            got++;
                    }

                    break;
                }
            }

            if (flag)
                l = m + 1;
            else
                r = m - 1;
        }

        std::cout << res << ' ' << L << ' ' << R << '\n';
    }
    return 0;
}
