/**
 *    author:  feev1x
 *    created: 04.02.2025 09:06:38
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, INF = 1e9 + 6;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline void sub_self(int &a, int b) {
    a -= b;

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void umax(int &a, int b) {
    if (a < b) {
        a = b;
    }
}

inline void umin(int &a, int b) {
    if (a > b) {
        a = b;
    }
}

struct Segtree {
    std::vector<int> t, psh, mn, mn2, cnt;
    int n;

    inline void merge(int v) {
        t[v] = t[v << 1];
        add_self(t[v], t[v << 1 | 1]);
        
        mn[v] = std::min(mn[v << 1], mn[v << 1 | 1]);

        mn2[v] = INF;
        cnt[v] = 0;

        if (mn[v << 1] != mn[v]) {
            umin(mn2[v], mn[v << 1]);
            
            cnt[v] = cnt[v << 1 | 1];
        }

        if (mn[v << 1 | 1] != mn[v]) {
            umin(mn2[v], mn[v << 1 | 1]);

            cnt[v] = cnt[v << 1];
        }

        if (!cnt[v]) {
            cnt[v] = cnt[v << 1] + cnt[v << 1 | 1];
        }

        if (mn2[v << 1] != mn[v]) {
            umin(mn2[v], mn2[v << 1]);
        }

        if (mn2[v << 1 | 1] != mn[v]) {
            umin(mn2[v], mn2[v << 1 | 1]);
        }
    }

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            mn[v] = 0;
            mn2[v] = INF;
            cnt[v] = 1;
            t[v] = 0;
            psh[v] = 0;

            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        merge(v);
    }

    Segtree(int _n) : n(_n) {
        t.resize(n * 4 + 5);
        psh.resize(n * 4 + 5);
        mn.resize(n * 4 + 5);
        mn2.resize(n * 4 + 5);
        cnt.resize(n * 4 + 5);

        build(1, 1, n);
    }

    inline void push(int v) {
        if (mn[v << 1] == mn[v << 1 | 1]) {
            psh[v << 1] = psh[v << 1 | 1] = psh[v];
            
            sub_self(t[v << 1], mul(mn[v << 1], cnt[v << 1]));
            add_self(t[v << 1], mul(mn[v], cnt[v << 1]));

            sub_self(t[v << 1 | 1], mul(mn[v << 1 | 1], cnt[v << 1 | 1]));
            add_self(t[v << 1 | 1], mul(mn[v], cnt[v << 1 | 1]));

            mn[v << 1] = mn[v << 1 | 1] = mn[v];

        } else if (mn[v << 1] > mn[v << 1 | 1]) {
            psh[v << 1 | 1] = psh[v];

            sub_self(t[v << 1 | 1], mul(mn[v << 1 | 1], cnt[v << 1 | 1]));
            add_self(t[v << 1 | 1], mul(mn[v], cnt[v << 1 | 1]));

            mn[v << 1 | 1] = mn[v];
        } else {
            psh[v << 1] = psh[v];

            sub_self(t[v << 1], mul(mn[v << 1], cnt[v << 1]));
            add_self(t[v << 1], mul(mn[v], cnt[v << 1]));

            mn[v << 1] = mn[v];
        }
    }

    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl > r || l > tr || mn[v] >= x) {
            return;
        }

        if (l <= tl && tr <= r && mn2[v] > x) {
            psh[v] = x;

            sub_self(t[v], mul(mn[v], cnt[v]));
            add_self(t[v], mul(x, cnt[v]));

            mn[v] = x;

            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        merge(v);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        push(v);

        int tm = tl + tr >> 1;

        int res = get(v << 1, tl, tm, l, r);
        add_self(res, get(v << 1 | 1, tm + 1, tr, l, r));

        return res;
    }

    inline void modify(int l, int r, int x) { // umax
        update(1, 1, n, l, r, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int C; std::cin >> C;

    int n, q; std::cin >> n >> q;

    std::vector<int> x(n);
    for (auto &u: x) {
        std::cin >> u;
    }

    std::map<int, std::vector<std::pair<int, int>>> mp;
    std::vector<int> ql(q), qr(q), ans(q), r(n);
    for (int i = 0; i < q; ++i) {
        std::cin >> ql[i] >> qr[i]; ql[i]--, qr[i]--;

        mp[ql[i]].emplace_back(qr[i], i);
    }
    
    std::stack<int> stk;
    for (int i = 0; i < n; ++i) {
        if (x[i]) {
            stk.emplace(i);
        } else {
            r[stk.top()] = i;

            stk.pop();
        }
    }

    Segtree t(n);
    for (int i = n - 1; i >= 0; --i) {
        if (!x[i]) {
            continue;
        }

        t.modify(i + 1, r[i], x[i]);

        for (auto [right, j]: mp[i]) {
            ans[j] = t.get(i + 1, right + 1);
        }
    }

    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}
