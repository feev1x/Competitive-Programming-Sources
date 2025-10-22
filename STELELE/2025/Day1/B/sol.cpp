/**
 *    author:  feev1x
 *    created: 18.10.2025 13:51:10
**/
#include <bits/stdc++.h>

inline void chmax(int &a, int b) {
    if (a < b)
        a = b;
}

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(2 * n);
    }

    inline void update(int l, int r, int x) {
        for (l += n - 1, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                chmax(t[l++], x);

            if (r & 1)
                chmax(t[--r], x);
        }
    }

    inline int get(int i) {
        int res = t[i += n - 1];

        for (i >>= 1; i > 0; i >>= 1)
            chmax(res, t[i]);

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;    

    Segtree t(n);
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        pos[a[i]].emplace_back(i);
    }

    {
        int x = 0;
        int ls = 0;
        for (auto u: pos[x])
            t.update(ls + 1, u, u), ls = u;

        if (ls + 1 <= n)
            t.update(ls + 1, n, n + 1);
    }
    
    for (int x = 1; x <= n; ++x) {
        int res = 0;

        int ls = 0;
        for (auto u: pos[x])
            t.update(ls + 1, u, u), ls = u;

        if (ls + 1 <= n)
            t.update(ls + 1, n, n + 1);

        for (int l = 1; l <= n; l = t.get(l))
            res++;

        std::cout << res << " \n"[x == n];
    }

    return 0;
}
