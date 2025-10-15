/**
 *    author:  feev1x
 *    created: 09.02.2025 17:03:30
**/
#include <bits/stdc++.h>
#include "modulosum.h"

constexpr int NN = 3e5;


struct Bit {
    std::vector<int> p;
    int n;
    
    Bit(int _n) : n(_n) {
        p.resize(n);
    }

    inline void update(int r, int x) {
        r = n - r + 1;

        for (; r <= n; r += r & -r)
            p[r] += x;
    }

    inline int get(int r) {
        r = n - r + 1;

        int res = 0;
        for (; r >= 1; r -= r & -r)
            res += p[r];

        return res;
    }
};


std::vector <long long> solve(
    int n, int q,
    std::vector <int> a,
    std::vector <int> L,
    std::vector <int> R,
    std::vector <int> M
) {

    int N = 3e5 + 5;
    std::vector<long long> ans(q);
    std::vector<int64_t> p(n + 1);
    for (int i = 0; i < n; ++i)
        p[i + 1] = p[i] + a[i];
    
    Bit bit(N);
    std::vector<std::vector<int>> del(n), add(n);
    std::vector<int> idx;
    for (int i = 0; i < q; ++i)
        if (M[i] >= 3000) {
            if (L[i])
                del[L[i] - 1].emplace_back(i);

            add[R[i]].emplace_back(i);

            ans[i] += p[R[i] + 1] - p[L[i]];
        } else
            idx.emplace_back(i);

    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return M[i] < M[j];
    });

    std::vector<int64_t> pref(n + 1);

    int ls = 0;
    for (auto i: idx) {
        if (ls != M[i])
            for (int j = 0; j < n; ++j)
                pref[j + 1] = pref[j] + (a[j] % M[i]);

        ls = M[i];

        ans[i] = pref[R[i] + 1] - pref[L[i]];
    }

    for (int i = 0; i < n; ++i) {
        bit.update(a[i], 1);

        for (auto j: del[i])
            for (int k = 1; k * M[j] < N; ++k)
                ans[j] += (int64_t)bit.get(k * M[j]) * M[j];

        for (auto j: add[i])
            for (int k = 1; k * M[j] < N; ++k)
                ans[j] -= (int64_t)bit.get(k * M[j]) * M[j];
    }

    return ans;
}
