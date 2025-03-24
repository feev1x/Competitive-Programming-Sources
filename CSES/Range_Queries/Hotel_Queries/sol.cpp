/**
 *    author:  feev1x
 *    created: 04.03.2025 16:38:10
**/
#include <bits/stdc++.h>

struct Segtree {
    std::vector<int> t;
    int n;

    Segtree(int _n) : n(_n) {
        t.resize(2 * n);
    }

    inline void update(int pos, int x) {
        for (t[pos += n - 1] -= x; pos >>= 1;) {
            t[pos] = std::max(t[pos << 1], t[pos << 1 | 1]);
        }
    }

    inline int get(int l, int r) {
        l += n - 1, r += n;

        int res = 0;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res = std::max(res, t[l++]);
            }

            if (r & 1) {
                res = std::max(t[--r], res);
            }
        }

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    Segtree t(n);
    for (int i = 1; i <= n; ++i) {
        int u; std::cin >> u;

        t.update(i, -u);
    }

    for (int i = 1; i <= m; ++i) {
        int u; std::cin >> u;

        int l = 1, r = n, ans = 0;
        while (l <= r) {
            int _m = l + r >> 1;

            if (t.get(1, _m) >= u) {
                r = _m - 1, ans = _m;
            } else {
                l = _m + 1;
            }
        }

        std::cout << ans << " \n"[i == m];

        if (ans) {
            t.update(ans, u);
        }
    }
    return 0;
}
