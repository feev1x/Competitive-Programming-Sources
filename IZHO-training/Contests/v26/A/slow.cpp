#include <bits/stdc++.h>

inline bool chmax(int64_t &a, int64_t b) {
    if (a <= b) {
        a = b;
        return true;
    }

    return false;
}

inline bool chmin(int64_t &a, int64_t b) {
    if (a >= b) {
        a = b;
        return true;
    }

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q; std::cin >> n >> q;

    std::vector<int> a(n + 1);
    std::vector<int64_t> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        p[i] = p[i - 1] + a[i];
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 2) {
            int x, v; std::cin >> x >> v;

            a[x] = v;
        } else {
            int ql, qr; std::cin >> ql >> qr;

            int64_t l = 0, r = 1e13, ans = -1;
            while (l <= r) {
                int64_t m = l + r >> 1;

                int64_t mx = 0, mn = 0;
                for (int i = ql; i <= qr; ++i) {
                    int64_t new_mx = std::max(mn + a[i], mx + a[i]);
                    int64_t new_mn = std::min(mn + a[i], mx + a[i]);

                    if (std::abs(mx) >= m || std::abs(mn) >= m) {
                        chmax(new_mx, a[i]);
                        chmin(new_mn, a[i]);
                    }

                    std::swap(new_mx, mx);
                    std::swap(new_mn, mn);
                }

                if (std::abs(mx) >= m || std::abs(mn) >= m) {
                    l = m + 1, ans = m;
                } else {
                    r = m - 1;
                }
            }

            assert(ans != -1);
            std::cout << ans << '\n';
        }
    }

    return 0;
}
