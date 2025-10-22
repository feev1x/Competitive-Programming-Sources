/**
 *    author:  feev1x
 *    created: 21.10.2025 09:58:04
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
    std::vector<int> t, psh;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n);
        psh.assign(4 * n, -1);
    }

    inline void push(int v, int tl, int tr) {
        if (psh[v] != -1) {
            psh[v << 1] = psh[v << 1 | 1] = psh[v];

            int tm = tl + tr >> 1;
            t[v << 1] = (tm - tl + 1) * psh[v];
            t[v << 1 | 1] = (tr - tm) * psh[v];

            psh[v] = -1;
        }
    }

    inline void set(int v, int tl, int tr, int l, int r, int x) {
        if (tl > r || l > tr)
            return;

        if (l <= tl && tr <= r) {
            t[v] = (tr - tl + 1) * x;
            psh[v] = x;
            return;
        }

        push(v, tl, tr);

        int tm = tl + tr >> 1;

        set(v << 1, tl, tm, l, r, x);
        set(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr)
            return 0;

        if (l <= tl && tr <= r)
            return t[v];

        push(v, tl, tr);

        int tm = tl + tr >> 1;
        return get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r);
    }

    inline void set(int l, int r, int x) {
        set(1, 1, n, l, r, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q, x; std::cin >> n >> q >> x;    

    Segtree t(n);
    int pos = -1;
    for (int i = 1; i <= n; ++i) {
        int u; std::cin >> u;

        if (u == x)
            pos = i;

        if (u <= x)
            u = 0;
        else if (u > x)
            u = 1;

        t.set(i, i, u);
    }

    while (q--) {
        int c, l, r; std::cin >> c >> l >> r;

        int cnt = t.get(l, r);
        t.set(l, r, 0);

        if (c == 1) {
            t.set(r - cnt + 1, r, 1);

            if (l <= pos && pos <= r)
                pos = r - cnt;
        } else {
            t.set(l, l + cnt - 1, 1);

            if (l <= pos && pos <= r)
                pos = l + cnt;
        }
    }

    std::cout << pos << '\n';
    return 0;
}
