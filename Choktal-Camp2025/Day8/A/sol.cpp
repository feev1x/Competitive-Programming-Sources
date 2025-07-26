/**
 *    author:  feev1x
 *    created: 08.07.2025 09:17:26
**/
#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

inline void chmin(int64_t &a, int64_t b) {
    if (a > b) {
        a = b;
    }
}

struct Segtree {
    std::vector<int64_t> t, p, s, ps, al, a, b;
    int n;

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            p[v] = s[v] = ps[v] = 0;

            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        t[v] = t[v << 1] + t[v << 1 | 1];
        p[v] = t[v << 1] + p[v << 1 | 1];
        s[v] = s[v << 1] + t[v << 1 | 1];
        ps[v] = s[v << 1] + p[v << 1 | 1];
    }

    Segtree(int _n, std::vector<int64_t> _a, std::vector<int64_t> _b) : n(_n), a(_a), b(_b) {
        t.assign(4 * n + 1, INF);
        p.assign(4 * n + 1, INF);
        s.assign(4 * n + 1, INF);
        ps.assign(4 * n + 1, INF);
        al.resize(4 * n + 1);

        build(1, 1, n);
    }

    inline void update(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return;
        }

        int tm = (tl + tr) >> 1;

        if (l <= tm && r > tm) {
            al[v] = 1;
        } else {
            update(v << 1, tl, tm, l, r);
            update(v << 1 | 1, tm + 1, tr, l, r);
        }

        if (al[v]) {
            if (tr - tl + 1 > 1)
                t[v] = std::min(t[v << 1] + t[v << 1 | 1], p[v << 1] + b[tm] + b[tm + 1] + s[v << 1 | 1]);
            else
                t[v] = a[tl];

            if (tr - tl + 1 > 3)
                p[v] = std::min(t[v << 1] + p[v << 1 | 1], p[v << 1] + b[tm] + b[tm + 1] + ps[v << 1 | 1]);
            else 
                p[v] = t[v << 1] + p[v << 1 | 1];

            if (tr - tl + 1 > 2)
                s[v] = std::min(s[v << 1] + t[v << 1 | 1], ps[v << 1] + b[tm] + b[tm + 1] + s[v << 1 | 1]);
            else
                s[v] = s[v << 1] + t[v << 1 | 1];

            if (tr - tl + 1 > 3)
                ps[v] = std::min(s[v << 1] + p[v << 1 | 1], ps[v << 1] + b[tm] + b[tm + 1] + ps[v << 1 | 1]);
            else
                ps[v] = s[v << 1] + p[v << 1 | 1];

        } else {
            t[v] = t[v << 1] + t[v << 1 | 1];
            p[v] = t[v << 1] + p[v << 1 | 1];
            s[v] = s[v << 1] + t[v << 1 | 1];
            ps[v] = s[v << 1] + p[v << 1 | 1];
        }
    }

    inline int get() {
        return t[1];
    }

    inline void update(int l, int r) {
        l++, r++;
        update(1, 1, n, l, r);
    }
};

std::vector<long long> calculate_costs(std::vector<int> w, std::vector<int> a, std::vector<int> b, std::vector<int> e) {
    std::vector<long long> ans;
    int n = a.size();

    std::vector<int> idx(n);

    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return w[i] < w[j];
    });

    if (e.size() <= 5) {
        for (auto d: e) {
            std::vector<int64_t> dp(n, INF);

            for (int i = 0; i < n; ++i) {
                chmin(dp[i], (i ? dp[i - 1] : 0) + a[idx[i]]);

                if (i > 0 && w[idx[i]] - w[idx[i - 1]] <= d)
                    chmin(dp[i], (i - 2 >= 0 ? dp[i - 2] : 0) + b[idx[i - 1]] + b[idx[i]]);

                if (i > 1 && w[idx[i]] - w[idx[i - 2]] <= d)
                    chmin(dp[i], (i - 3 >= 0 ? dp[i - 3] : 0) + b[idx[i - 2]] + b[idx[i]] + a[idx[i - 1]]);
            }

            ans.emplace_back(dp.back());
        }

        return ans;
    }

    ans.resize(e.size());
    std::vector<int64_t> _a(1), _b(1);
    for (int i = 0; i < n; ++i) {
        _a.emplace_back(a[idx[i]]);
        _b.emplace_back(b[idx[i]]);
    }

    Segtree t(n, _a, _b);

    std::vector<std::pair<int, int>> sm(e.size());
    for (int i = 0; i < e.size(); ++i) {
        sm[i] = {e[i], i};
    }

    std::sort(sm.begin(), sm.end());

    std::vector<std::vector<std::pair<int, int>>> add(e.size());
    for (int i = 1; i < n; ++i) {
        int j = idx[i], k = idx[i - 1];

        int val = w[j] - w[k];

        int l = std::lower_bound(sm.begin(), sm.end(), std::pair{val, -1}) - sm.begin();

        if (l == e.size()) {
            continue;
        }

        add[sm[l].second].emplace_back(i - 1, i);
    }

    for (auto [d, i]: sm) {
        for (auto [l, r]: add[i]) {
            t.update(l, r);
        }

        ans[i] = t.get();
    }

    return ans;
}
