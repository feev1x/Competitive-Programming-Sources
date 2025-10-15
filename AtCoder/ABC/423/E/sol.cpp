/**
 *    author:  feev1x
 *    created: 14.09.2025 19:25:52
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

#define int int64_t

struct Node {
    int s1 = 0, s2 = 0, s3 = 0, sum = 0, sz = 0;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
    }

    inline Node comb(Node a, Node b) {
        Node res;

        res.sum = a.sum + b.sum;
        res.s2 = a.s2 + b.s2 + b.sum * a.sz;
        res.s3 = a.s3 + b.s3 + a.sum * b.sz;
        res.s1 = a.s1 + a.s2 * b.sz + b.s1 + b.s3 * a.sz;
        res.sz = a.sz + b.sz;

        return res;
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = {x, x, x, x, 1};
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
            return {0, 0, 0, 0, 0};

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;
        return comb(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r).s1;
    }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Segtree t(n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        t.update(i, a[i]);
    }

    while (q--) {
        int l, r; std::cin >> l >> r;

        std::cout << t.get(l, r) << '\n';
    }
    return 0;
}
