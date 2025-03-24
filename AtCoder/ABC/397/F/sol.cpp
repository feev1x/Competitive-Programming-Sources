/**
 *    author:  feev1x
 *    created: 15.03.2025 18:38:37
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int> t, psh;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n + 1);
        psh.resize(4 * n + 1);
    }

    inline void push(int v) {
        psh[v << 1] += psh[v];
        psh[v << 1 | 1] += psh[v];

        t[v << 1] += psh[v];
        t[v << 1 | 1] += psh[v];


        psh[v] = 0;
    }

    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl > r || l > tr) {
            return;
        }

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

    inline int get(int v, int tl, int tr, int l, int r) {
        if (tl > r || l > tr) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        push(v);

        int tm = tl + tr >> 1;

        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int l, int r, int x) {
        update(1, 1, n, l, r, x);
    }

    inline int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
        
    int n; std::cin >> n;

    Segtree t(n);
    std::map<int, int> mp1, mp2;
    std::map<int, std::deque<int>> pos;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        mp2[u]++;
    }

    for (int i = 0; i < n; ++i) {
        pos[a[i]].emplace_back(i + 1);
    }

    for (auto [key, val]: pos) {
        if (val.size() > 1) {
            t.update(val.front(), val.back() - 1, 1);
        }
    }

    int res = 0;
    for (int i = 0; i + 1 < n; ++i) {
        mp1[a[i]]++;
        mp2[a[i]]--;

        if (pos[a[i]].size() > 1) {
            t.update(pos[a[i]].front(), pos[a[i]].back() - 1, -1);
        }

        pos[a[i]].pop_front();

        if (pos[a[i]].size() > 1) {
            t.update(pos[a[i]].front(), pos[a[i]].back() - 1, 1);
        }

        if (!mp2[a[i]]) {
            mp2.erase(a[i]);
        }
        
        res = std::max(res, (int)mp1.size() + (int)mp2.size() + t.get(i + 1, n));
    }

    std::cout << res << '\n';
    return 0;
}
