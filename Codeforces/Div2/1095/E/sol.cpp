#include <bits/stdc++.h>

constexpr int INF = 1e9, SINF = 1e8;

struct Segtree {
    std::vector<int> t, psh;
    int n;
    Segtree(int n) : n(n) { t.resize(4 * n), psh.resize(4 * n); }
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
        int tm = tl + tr >> 1; push(v);
        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);
        t[v] = std::min(t[v << 1], t[v << 1 | 1]);
    }
    inline int get(int v, int tl, int tr, int i) {
        if (tl == tr) return t[v];
        int tm = tl + tr >> 1;
        if (i <= tm) return get(v << 1, tl, tm, i) + psh[v];
        return get(v << 1 | 1, tm + 1, tr, i) + psh[v];
    }
    inline void update(int l, int r, int x) { update(1, 0, n - 1, l, r, x); }
    inline int get() { return t[1]; }
    inline int get(int i) { return get(1, 0, n - 1, i); }
};

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n), mxmex(n);
    std::multiset<int> st;
    int mx = 0;
    for (auto &u: a) std::cin >> u, mx = std::max(mx, u + 1);
    Segtree t(mx);
    if (a[0] == 0) t.update(0, 0, INF);
    else st.emplace(a[0]), t.update(0, std::max(0, (a[0] + 1) / 2 - 1), 1);
    for (int mex = 1, mn = 0; mex <= mx && mn < n; ++mex) {
        t.update(0, mex - 1, -1);
        if (st.size() && st.find(mex - 1) != st.end()) {
            t.update(0, std::max(0, mex / 2 - 1), -1);
            t.update(mex - 1, mex - 1, INF);
            t.update(0, mex - 1, 1);
            st.erase(st.find(mex - 1));
        }
        while (t.get() < 0 && ++mn < n) {
            if (a[mn] < mex && t.get(a[mn]) < SINF) t.update(a[mn], a[mn], INF), t.update(0, a[mn], 1);
            else st.emplace(a[mn]), t.update(0, std::max(0, (a[mn] + 1) / 2 - 1), 1);
        }
        if (mn >= n) break;
        mxmex[mn] = mex;
    }
    int mex = 0;
    for (int i = 0; i < n; ++i) {
        mex = std::max(mex, mxmex[i]);
        std::cout << mex << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
