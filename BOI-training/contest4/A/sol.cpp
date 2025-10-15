/**
 *    author:  feev1x
 *    created: 12.09.2025 17:14:50
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

        t[v] = t[v << 1] + t[v << 1 | 1];
    }

    inline std::array<int, 3> get(int v, int tl, int tr, int x) {
        if (tl == tr)
            return {tl, x, t[v]};

        int tm = tl + tr >> 1;

        if (t[v << 1] < x)
            return get(v << 1 | 1, tm + 1, tr, x - t[v << 1]); 

        return get(v << 1, tl, tm, x);
    }

    inline void update(int i, int x) {
        update(1, 1, n, i, x);
    }

    inline std::array<int, 3> get(int x) {
        return get(1, 1, n, x);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n), next(n), pos(n + 1);
    for (auto &u: a)
        std::cin >> u;

    std::stack<int> stk;
    for (int i = n - 1; i >= n / 2; --i) {
        pos[a[i]] = i;

        while (stk.size() && a[stk.top()] < a[i])
            stk.pop();

        if (stk.size())
            next[i] = stk.top();
        else
            next[i] = n;

        stk.emplace(i);
    }

    while (stk.size())
        stk.pop();

    for (int i = n / 2 - 1; i >= 0; --i) {
        pos[a[i]] = i;

        while (stk.size() && a[stk.top()] < a[i])
            stk.pop();

        if (stk.size())
            next[i] = stk.top();
        else
            next[i] = n / 2;

        stk.emplace(i);
    }

    Segtree t(n);
    for (int i = 0; i < n; i = next[i])
        t.update(a[i], next[i] - i);

    std::vector<int> ans(q);
    std::vector<std::vector<std::pair<int, int>>> qt(2 * n + 1);
    for (int i = 0; i < q; ++i) {
        int t, j; std::cin >> t >> j;

        if (t > 2 * n) {
            t = 2 * n;
        }

        if (t)
            qt[t].emplace_back(j, i);
        else
            ans[i] = a[j - 1];
    }

    bool flag = false;
    for (int idx = 1; idx <= 2 * n; ++idx) {
        for (auto [val, i]: qt[idx]) {
            auto ar = t.get(val);

            ans[i] = a[pos[ar[0]] + ar[1] - 1];
        }

        if (flag)
            continue;

        auto ar = t.get(n / 2);

        if (ar[1] == ar[2]) {
            flag = true;
            continue;
        }

        t.update(ar[0], ar[1]);

        int l = pos[ar[0]] + ar[1], r = pos[ar[0]] + ar[2] - 1;
        for (int nw = l; ; nw = next[nw]) {
            if (next[nw] > r) {
                t.update(a[nw], r - nw + 1);
                break;
            } else 
                t.update(a[nw], next[nw] - nw);
        }
    }

    assert(flag);

    for (auto u: ans)
        std::cout << u << '\n';
    return 0;
}
