#include <bits/stdc++.h>

struct Segtree {
    std::vector<int> t, psh;
    int n;
    Segtree(int n) : n(n) {
        t.resize(4 * n);
        psh.resize(4 * n);
    }
    inline void push(int v) {
        if (psh[v]) {
            t[v << 1] += psh[v];
            t[v << 1 | 1] += psh[v];
            psh[v << 1] += psh[v];
            psh[v << 1 | 1] += psh[v];
            psh[v] = 0;
        }
    }
    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (l > tr || tl > r) return;
        if (l <= tl && tr <= r) return t[v] += x, psh[v] += x, void();
        push(v);
        int tm = tl + tr >> 1;
        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);
        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }
    inline void set(int v, int tl, int tr, int i, int x) {
        if (tl == tr) return t[v] = x, void();
        push(v);
        int tm = tl + tr >> 1;
        if (i <= tm) set(v << 1, tl, tm, i, x);
        else set(v << 1 | 1, tm + 1, tr, i, x);
        t[v] = std::max(t[v << 1], t[v << 1 | 1]);
    }
    inline int get() { return t[1]; }
    inline void update(int l, int r, int x) { update(1, 0, n - 1, l, r, x); }
    inline void set(int i, int x) { set(1, 0, n - 1, i, x); }
};

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    Segtree t(n + 1);
    for (int i = 0; i < n; ++i) {
        t.set(a[i], 0);
        if (a[i]) t.update(0, a[i] - 1, 1);
        std::cout << t.get() << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
