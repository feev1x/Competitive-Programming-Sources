#include <bits/stdc++.h>

constexpr int INF = 2e9;

struct Node {
    int l = 0, r = 0, psh = 0, mnp = 0;
};

struct Segtree {
    std::vector<Node> t;
    std::vector<int> ans, p, a;
    int n, nw = 0;
    inline Node comb(Node a, Node b) {
        Node res;
        res.l = std::max(a.l, b.l);
        res.r = std::min(a.r, b.r);
        res.mnp = std::min(a.mnp, b.mnp);
        return res;
    }
    inline void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = {a[tl] - p[tl], a[tl] + p[tl], 0, p[tl]};
            return;
        }
        int tm = tl + tr >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
    Segtree(std::vector<int> p, std::vector<int> a) : p(p), a(a), n(a.size() - 1) {
        t.resize(4 * n);
        ans.resize(n + 1);
        build(1, 1, n);
    }
    inline void push(int v) {
        if (t[v].psh) {
            t[v << 1] = {t[v].psh - t[v << 1].mnp, t[v].psh + t[v << 1].mnp, t[v].psh, t[v << 1].mnp};
            t[v << 1 | 1] = {t[v].psh - t[v << 1 | 1].mnp, t[v].psh + t[v << 1 | 1].mnp, t[v].psh, t[v << 1 | 1].mnp};
            t[v].psh = 0;
        }
    }
    inline void update(int v, int tl, int tr, int l, int r, int x) {
        if (tl > r || l > tr) return;
        if (l <= tl && tr <= r) {
            if (t[v].l <= x && x <= t[v].r) {
                t[v] = {x - t[v].mnp, x + t[v].mnp, x, t[v].mnp};
                return;
            }
            if (tl == tr) {
                ans[tl] = nw;
                t[v] = {-INF, INF, 0, INF / 2};
                return;
            }
        }
        push(v);
        int tm = tl + tr >> 1;
        update(v << 1, tl, tm, l, r, x);
        update(v << 1 | 1, tm + 1, tr, l, r, x);
        t[v] = comb(t[v << 1], t[v << 1 | 1]);
    }
    inline void update(int l, int r, int x) {
        nw++; update(1, 1, n, l, r, x);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) std::cin >> p[i];
    Segtree t(p, a);
    while (q--) {
        int l, r, x; std::cin >> l >> r >> x;
        t.update(l, r, x);
    }
    for (int i = 1; i <= n; ++i) std::cout << t.ans[i] << " \n"[i == n];
    return 0;
}
