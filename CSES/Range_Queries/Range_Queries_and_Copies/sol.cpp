/**
 *    author:  feev1x
 *    created: 24.03.2025 15:01:06
**/
#include <bits/stdc++.h>

struct Node {
    int64_t sum;

    Node *l, *r;

    Node() : sum(0), l(nullptr), r(nullptr) {}
    Node(int _sum) : sum(_sum), l(nullptr), r(nullptr) {}

    inline void rec() {
        sum = l->sum + r->sum;
    }
};

struct Pst {
    std::vector<Node*> rts;
    int n;

    inline Node *build(int tl, int tr) {
        Node *cur = new Node();

        if (tl == tr) {
            return cur;
        }

        int tm = tl + tr >> 1;

        cur->l = build(tl, tm);
        cur->r = build(tm + 1, tr);
        cur->rec();

        return cur;
    }

    Pst(int _n) : n(_n) {
        rts.resize(2);

        rts[1] = build(1, n);
    }

    inline Node *update(Node *old, int tl, int tr, int i, int x) {
        Node *cur = new Node(*old);

        if (tl == tr) {
            cur->sum = x;

            return cur;
        }

        int tm = tl + tr >> 1;

        if (i <= tm) {
            cur->l = update(old->l, tl, tm, i, x);
        } else {
            cur->r = update(old->r, tm + 1, tr, i, x);
        }

        cur->rec();

        return cur;
    }

    inline int64_t get(Node *cur, int tl, int tr, int l, int r) {
        if (l > tr || tl > r) {
            return 0ll;
        }
        
        if (l <= tl && tr <= r) {
            return cur->sum;
        }

        int tm = tl + tr >> 1;

        return get(cur->l, tl, tm, l, r) + get(cur->r, tm + 1, tr, l, r);
    }

    inline void set(int k, int i, int x) {
        rts[k] = update(rts[k], 1, n, i, x);
    }

    inline int64_t get(int k, int l, int r) {
        return get(rts[k], 1, n, l, r);
    }
    
    inline void copy(int k) {
        rts.emplace_back(new Node(*rts[k]));
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Pst t(n);

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        t.set(1, i, a[i]);
    }

    while (q--) {
        int type, k; std::cin >> type >> k;

        if (type == 1) {
            int i, x; std::cin >> i >> x;

            t.set(k, i, x);
        } else if (type == 2) {
            int l, r; std::cin >> l >> r;

            std::cout << t.get(k, l, r) << '\n';
        } else {
            t.copy(k);
        }
    }
    return 0;
}
