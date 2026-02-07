#include <bits/stdc++.h>

constexpr int64_t INF = 1e18;

struct Segtree {
    std::vector<int64_t> t, psh;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(4 * n);
        psh.resize(4 * n);
    }

    inline void push(int v) {
        if (psh[v]) {
            t[v << 1] += psh[v];
            psh[v << 1] += psh[v];
            t[v << 1 | 1] += psh[v];
            psh[v << 1 | 1] += psh[v];

            psh[v] = 0;
        }
    }

    inline void update(int v, int tl, int tr, int l, int r, int64_t x) {
        if (l > tr || tl > r) {
            return;
        }

        if (l <= tl && tr <= r) {
            psh[v] += x;
            t[v] += x;
            return;
        }

        int tm = tl + tr >> 1;

        push(v);

        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);

        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }

    inline int64_t get(int v, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return 0;
        }

        if (l <= tl && tr <= r) {
            return t[v];
        }

        push(v);

        int tm = tl + tr >> 1;
        return std::max(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
    }

    inline void update(int l, int r, int64_t x) {
        update(1, 1, n, l, r, x);
    }

    inline int64_t get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q; std::cin >> n >> q;

    Segtree t(n);

    std::vector<int> next(n + 1), prev(n + 1);
    std::set<int> st;
    for (int i = 1; i <= n; ++i) {
        st.emplace(i);
        next[i] = i + 1;
        prev[i] = i - 1;
    }

    auto Del = [&](int i) {
        t.update(i, i, -INF);

        if (next[i] != n + 1) {
            prev[next[i]] = prev[i];
        }

        if (prev[i]) {
            next[prev[i]] = next[i];
        }
    };

    while (q--) {
        int type, l, r; std::cin >> type >> l >> r;

        if (type == 1) {
            int64_t x; std::cin >> x;

            t.update(l, r, x);
        } else if (type == 2) {
            int val = *st.lower_bound(l);

            while (val <= r) {
                Del(val);

                val = next[val];
            }
        } else {
            std::cout << std::max((int64_t)0, t.get(l, r)) << '\n';
        }
    }

    return 0;
}
