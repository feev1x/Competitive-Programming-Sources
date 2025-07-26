/**
 *    author:  feev1x
 *    created: 03.07.2025 09:28:58
**/
#include <bits/stdc++.h>

#define int int64_t

struct Segtree {
    std::vector<int64_t> t, cnt;
    std::vector<bool> psh;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
        cnt.resize(4 * n + 1);
        psh.resize(4 * n + 1);
    }

    inline void push(int v) {
        if (psh[v]) {
            psh[v << 1] = psh[v << 1 | 1] = true;
            t[v << 1] = t[v << 1 | 1] = 0;
            cnt[v << 1] = cnt[v << 1 | 1] = 0;

            psh[v] = false;
        }
    }

    inline void update(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r || psh[v]) {
            return;
        }

        if (l <= tl && tr <= r) {
            psh[v] = true;

            t[v] = 0;
            cnt[v] = 0;

            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r);
        update(v << 1 | 1, tm + 1, tr, l, r);

        t[v] = t[v << 1] + t[v << 1 | 1];
        cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
    }

    inline void upd(int v, int tl, int tr, int pos, int64_t x) {
        if (tl == tr) {
            t[v] += x * pos;
            cnt[v] += x;
            psh[v] = false;

            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        if (pos <= tm) {
            upd(v << 1, tl, tm, pos, x);
        } else {
            upd(v << 1 | 1, tm + 1, tr, pos, x);
        }

        t[v] = t[v << 1] + t[v << 1 | 1];
        cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr || psh[v]) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        push(v);

        int tm = tl + tr >> 1;

        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline int coun(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr || psh[v]) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return cnt[v];
        }

        push(v);

        int tm = tl + tr >> 1;

        return coun(v << 1, tl, tm, l, r) + coun(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline void update(int l, int r) {
        update(1, 1, n, l, r);
    }

    inline void upd(int pos, int64_t x) {
        upd(1, 1, n, pos, x);
    }

    inline int64_t get(int l, int r) {
        return get(1, 1, n, l, r);
    }

    inline int coun(int l, int r) {
        return coun(1, 1, n, l, r);
    }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1);
    std::vector<std::vector<int64_t>> sz(n + 1, std::vector<int64_t>(m + 1));
    std::vector<std::vector<int>> jump(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];
        
        s[i] = " " + s[i];
    }

    int max = 0;
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (s[i][j] == '1' && sz[i][j] == 0) {
                int k = j;

                while (k <= m && s[i][k] == '1') {
                    k++;
                }

                k--;

                max = std::max(max, k - j + 1);
                for (int l = j; l <= k; ++l) {
                    sz[i][l] = k - l + 1;
                }
            }
        }
    }

    if (!max) {
        std::cout << "0\n";

        exit(0);
    }

    int64_t res = 0;
    for (int j = 1; j <= m; ++j) {
        int64_t cnt = 0;

        for (int i = 1; i <= n; ++i) {
            if (s[i][j] == '1') {
                int mn = 1e9;

                for (int k = i - 1; ;) {
                    if (k < 1 || sz[k][j] <= sz[i][j]) {
                        jump[i][j] = k + 1;
                        break;
                    }

                    mn = std::min(mn, sz[k][j]);

                    cnt -= mn * (k - jump[k][j] + 1);
                    cnt += sz[i][j] * (k - jump[k][j] + 1);

                    k = jump[k][j] - 1;
                }

                cnt += sz[i][j];
            } else {
                cnt = 0;
            }

            res = std::max(res, cnt);
        }
    }

    std::cout << res << '\n';
    return 0;
}

