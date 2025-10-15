/**
 *    author:  feev1x
 *    created: 08.10.2025 12:22:33
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

constexpr int64_t INF = 1e18;

struct Node {
    int cnt = 0; int64_t min = INF, psh = 0;
};

struct Segtree {
    std::vector<Node> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n);
    }

    inline Node comb(Node a, Node b) {
        Node res;

        res.cnt = a.cnt + b.cnt;
        res.min = std::min(a.min, b.min);

        return res;
    }

    inline void push(int v) {
        if (t[v].psh) {
            t[v << 1].min -= t[v].psh;
            t[v << 1 | 1].min -= t[v].psh;
            t[v << 1].psh += t[v].psh;
            t[v << 1 | 1].psh += t[v].psh;

            t[v].psh = 0;
        }
    }

    inline void update(int v, int tl, int tr, int i, int64_t x) {
        if (tl == tr) {
            t[v] = {0, x, 0};
            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }

    inline void update(int v, int tl, int tr, int l, int r, int k) {
        if (tl > r || l > tr)
            return;

        if (l <= tl && tr <= r) {
            t[v].psh += k;
            t[v].min -= k;
            return;
        }

        push(v);

        int tm = tl + tr >> 1;
        
        update(v << 1, tl, tm, l, r, k);
        update(v << 1 | 1, tm + 1, tr, l, r, k);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return 0;

        if (l <= tl && tr <= r)
            return t[v].cnt;

        push(v);

        int tm = tl + tr >> 1;
        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline int64_t get(int v, int tl, int tr, int l, int r, int k) {
        if (tl > r || l > tr || t[v].min >= 0)
            return (int64_t)0;

        int tm = tl + tr >> 1;
        if (l <= tl && tr <= r)
            if (tl == tr) {
                int64_t val = k + t[v].min;

                t[v] = {1, INF, 0};
                return val;
            }

        push(v);

        int64_t res = get(v << 1, tl, tm, l, r, k) + get(v << 1 | 1, tm + 1, tr, l, r, k);

        t[v] = comb(t[v << 1], t[v << 1 | 1]);
        return res;
    }

    inline void update(int i, int64_t x) {
        update(1, 1, n, i, x);
    }

    inline void update(int l, int r, int k) {
        update(1, 1, n, l, r, k);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }

    inline int64_t get(int l, int r, int k) {
        return get(1, 1, n, l, r, k);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    Segtree t(n);
    std::vector<int64_t> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], t.update(i, a[i]);

    int q; std::cin >> q;
    while (q--) {
        int l, r, k; std::cin >> l >> r >> k;

        t.update(l, r, k);
        std::cout << t.get(l, r, k) + (int64_t)(r - l + 1 - t.get(l, r)) * k << '\n';
    }

    return 0;
}
