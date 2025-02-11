/**
 *    author:  feev1x
 *    created: 09.02.2025 17:03:30
**/
#include <bits/stdc++.h>
#include "modulosum.h"

constexpr int NN = 3e5;

struct Segtree {
    std::vector<std::vector<int>> t;
    std::vector<int> a;
    int n;

    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v].emplace_back(a[tl]);
            return;
        }

        int tm = tl + tr >> 1;

        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);

        int l = 0, r = 0;
        while (l < t[v << 1].size() && r < t[v << 1 | 1].size()) {
            if (t[v << 1][l] > t[v << 1 | 1][r]) {
                t[v].emplace_back(t[v << 1 | 1][r++]);
            } else {
                t[v].emplace_back(t[v << 1][l++]);
            }
        }

        while (l < t[v << 1].size()) {
            t[v].emplace_back(t[v << 1][l++]);
        }

        while (r < t[v << 1 | 1].size()) {
            t[v].emplace_back(t[v << 1 | 1][r++]);
        }
    }

    Segtree(std::vector<int> _a) : n(_a.size()) {
        t.resize(n * 4 + 5);
        a.resize(n + 1);

        for (int i = 1; i <= n; ++i) {
            a[i] = _a[i - 1];
        }

        build(1, 1, n);
    }

    inline int get(int v, int tl, int tr, int l, int r, int m) {
        if (tl > r || l > tr || t[v].back() < m) {
            return 0;
        }

        int tm = tl + tr >> 1;

        if (t[v].front() >= m) {
            return std::min(tr, r) - std::max(tl, l) + 1;
        }

        if (l <= tl && tr <= r) {
            int j = std::lower_bound(t[v].begin(), t[v].end(), m) - t[v].begin();

            return (int)t[v].size() - j;
        }


        return get(v << 1, tl, tm, l, r, m) + get(v << 1 | 1, tm + 1, tr, l, r, m);
    }

    inline int get(int l, int r, int m) {
        return get(1, 1, n, l, r, m);
    }
};

std::vector <long long> solve(
    int n, int q,
    std::vector <int> a,
    std::vector <int> L,
    std::vector <int> R,
    std::vector <int> M
) {

//    int mx = *std::max_element(M.begin(), M.end());
//
//    std::vector<std::vector<int64_t>> p(n + 1, std::vector<int64_t>(NN));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 1; j < NN; ++j) {
//            p[i + 1][j] = p[i][j] + (a[i] % j);
//        }
//    }
//
    Segtree t(a);
    std::vector<int64_t> p(n + 1);
    for (int i = 0; i < n; ++i) {
        p[i + 1] = a[i] + p[i];
    }


    std::vector<long long> ans;
    for (int i = 0; i < q; ++i) {
//        if (M[i] < NN) {
//            int64_t sum = p[R[i] + 1][M[i]] - p[L[i]][M[i]];
//
//            ans.emplace_back(sum);
//        } else {
            int64_t res = 0, nw = 1;
            while (nw * M[i] <= NN) {
                int got = t.get(L[i] + 1, R[i] + 1, nw * M[i]);

                if (got) {
                    res += got;
                } else {
                    break;
                }

                nw++;
            }

            ans.emplace_back(p[R[i] + 1] - p[L[i]] - res * M[i]);
//        }
    }

    return ans;
}
