/**
 *    author:  feev1x
 *    created: 04.03.2025 15:35:15
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(2 * n);
    }

    inline void update(int pos, int x) {
        for (t[pos += n - 1] = x; pos >>= 1;) {
            t[pos] = std::min(t[pos << 1], t[pos << 1 ^ 1]);
        }
    }

    inline int get(int l, int r) {
        l += n - 1, r += n;
        
        int res = INF;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res = std::min(res, t[l++]);
            }

            if (r & 1) {
                res = std::min(t[--r], res);
            }
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    Segtree t(n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        t.update(i + 1, a[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int k, u; std::cin >> k >> u;

            t.update(k, u);
        } else {
            int l, r; std::cin >> l >> r;

            std::cout << t.get(l, r) << '\n';
        }
    }
    return 0;
}
