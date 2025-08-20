/**
 *    author:  feev1x
 *    created: 19.08.2025 21:09:37
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
        if (tl > r || l > tr)
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
    
    int n, q; std::cin >> n >> q;

    Segtree t(n);
    std::map<int, std::set<int>> mp;
    std::vector<int> a(n + 1), pv(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        
        if (mp[a[i]].size())
            pv[i] = *mp[a[i]].rbegin();

        mp[a[i]].emplace(i);

        t.update(i, pv[i]);
    }
    
    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int i, x; std::cin >> i >> x;

            {
                auto &st = mp[a[i]];
                auto it = st.lower_bound(i);

                if (next(it) != st.end()) {
                    pv[*next(it)] = it != st.begin() ? *prev(it) : 0;

                    t.update(*next(it), pv[*next(it)]);
                }

                st.erase(it);
            }

            a[i] = x;
            {
                auto &st = mp[a[i]];

                st.emplace(i);
                auto it = st.lower_bound(i);

                if (next(it) != st.end()) {
                    pv[*next(it)] = i;

                    t.update(*next(it), pv[*next(it)]);
                }

                pv[i] = it == st.begin() ? 0 : *prev(it);

                t.update(i, pv[i]);
            }
        } else {
            int l, r; std::cin >> l >> r;

            std::cout << (t.get(l, r) >= l ? "NO\n" : "YES\n");
        }
    }
    return 0;
}
