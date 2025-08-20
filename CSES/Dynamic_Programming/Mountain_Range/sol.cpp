/**
 *    author:  feev1x
 *    created: 19.08.2025 16:47:27
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
    std::vector<int> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
    }

    inline void update(int v, int tl, int tr, int i, int x) {
        if (tl == tr) {
            t[v] = x;
            return;
        }

        int tm = tl + tr >> 1;
        if (i <= tm)
            update(v << 1, tl, tm, i, x);
        else
            update(v << 1 | 1, tm + 1, tr, i, x);

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline int get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r)
            return 0;

        if (l <= tl && tr <= r)
            return t[v];

        int tm = tl + tr >> 1;
        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::stack<int> stk;
    std::vector<int> a(n + 1), l(n + 1), r(n + 1, n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        while (stk.size() && a[stk.top()] < a[i])
            stk.pop();

        if (stk.size())
            l[i] = stk.top();

        stk.emplace(i);
    }

    while (stk.size())
        stk.pop();

    for (int i = n; i >= 1; --i) {
        while (stk.size() && a[stk.top()] < a[i])
            stk.pop();

        if (stk.size())
            r[i] = stk.top();

        stk.emplace(i);
    }

    std::vector<int> idx(n);

    std::iota(idx.begin(), idx.end(), 1);
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    Segtree t(n);
    for (auto i: idx)
        t.update(i, t.get(l[i] + 1, r[i] - 1) + 1);

    std::cout << t.get(1, n) << '\n';
    return 0;
}
