/**
 *    author:  feev1x
 *    created: 04.03.2025 16:21:55
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int64_t> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(2 * n);
    }

    inline void update(int l, int r, int x) {
        l += n - 1, r += n;
        
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                t[l++] += x;
            }

            if (r & 1) {
                t[--r] += x;
            }
        }
    }

    inline int64_t get(int pos) {
        int64_t res = 0;

        for (res = t[pos += n - 1]; pos >>= 1;) {
            res += t[pos];
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

        t.update(i + 1, i + 1, a[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 1) {
            int l, r, x; std::cin >> l >> r >> x;

            t.update(l, r, x);
        } else {
            int k; std::cin >> k;

            std::cout << t.get(k) << '\n';
        }
    }
    return 0;
}
