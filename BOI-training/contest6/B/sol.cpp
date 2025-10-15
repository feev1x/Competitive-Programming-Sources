#include "highest.h"
#include <bits/stdc++.h>

struct Node {
    int val = 0, idx = 0;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    Segtree (int _n) : n(_n) {
        t.resize(4 * n + 1);
    }

    inline Node comb(Node x, Node y) {
        if (x.val > y.val)
            return x;
        else
            return y;
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = {x, tl};
            return;
        }

        int tm = tl + tr >> 1;
        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }

    inline Node get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return {0, 0};

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;
        return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int i, int val) {
        update(1, 1, n, i, val);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r).idx;
    }
};

std::vector<int> solve(std::vector<int> &V, std::vector<int> &W, std::vector<std::pair<int, int>> &queries) {
    int n = V.size();

    std::vector<int> v(1), w(1);
    for (auto u: V)
        v.emplace_back(u);

    for (auto u: W)
        w.emplace_back(u);

    for (int i = 1; i <= n; ++i) {
        v[i] += i, w[i] += i;

        v[i] = std::min(v[i], n);
        w[i] = std::min(w[i], n);
    }

    std::vector dp(n + 1, std::vector<int>(n + 1, n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            dp[i][i] = 0;

            for (int k = i; k <= j; ++k) {
                if (v[k] >= j)
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + 1);

                if (w[k] >= j)
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + 2);

                if (dp[i][j] <= 2)
                    break;
            }
        }


    std::vector<int> res;
    for (auto [a, b]: queries) {
        a++, b++;

        res.emplace_back(dp[a][b]);
    }

    return res;
}
