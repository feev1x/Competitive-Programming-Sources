/**
 *    author:  feev1x
 *    created: 10.09.2025 12:16:44
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,std::less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
    int n;
    std::vector<int64_t> t, psh;

    Segtree(int _n) : n(_n) {
        t.assign(4 * n + 1, 0);
        psh.assign(4 * n + 1, 0);
    }

    inline void push(int v) {
        if (psh[v]) {
            psh[v << 1] += psh[v];
            psh[v << 1 | 1] += psh[v];

            t[v << 1] += psh[v];
            t[v << 1 | 1] += psh[v];
        }

        psh[v] = 0;
    }

    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (l > tr || tl > r)
            return;

        if (l <= tl && tr <= r) {
            t[v] += x;
            psh[v] += x;

            return;
        }

        push(v);

        int tm = tl + tr >> 1;

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r)
            return 0;

        if (l <= tl && tr <= r)
            return std::max(t[v], (int64_t)0);

        push(v);

        int tm = tl + tr >> 1;

        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    inline int64_t get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::vector<std::array<int, 4>> ar(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ar[i][0] >> ar[i][1] >> ar[i][2];

        ar[i][3] = i + 1;
    }

    std::vector<int> pos(n + 1);
    std::sort(ar.begin(), ar.end());

    {
        int idx = 0;

        for (auto [a, b, c, i]: ar)
            pos[i] = ++idx;
    }

    std::sort(ar.begin(), ar.end(), [&](std::array<int, 4> a, std::array<int, 4> b) {
        return a[1] < b[1];
    });

    Segtree t(n);

    ordered_set st;

    int64_t res = 1e18;
    for (auto [a, b, c, i]: ar) {
        i = pos[i];

        t.update(i, i, a);

        if (i != n)
            t.update(i + 1, n, -c);

//        std::cout << a << ' ' << b << ' ' << c << ' ' << i << ' ' << t.get(4, 4) << '\n';
        st.insert(i);

        if (st.size() >= k)
            res = std::min(res, t.get(1, *st.find_by_order(k - 1)) + b);
    }

    std::cout << res << '\n';
    return 0;
}
