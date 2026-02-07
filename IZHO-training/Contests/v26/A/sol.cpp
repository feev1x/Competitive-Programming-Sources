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

//    int mx = -1e9, mn = 1e9;
//    int64_t mxp = -1e18, mnp = 1e18;
    std::vector<int> a(n + 1);
    std::vector<int64_t> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

//        mx = std::max(mx, a[i]);
//        mn = std::min(mn, a[i]);

        p[i] = p[i - 1] + a[i];

//        mxp = std::max(mxp, p[i]);
//        mnp = std::min(mnp, p[i]);
    }

    while (q--) {
        int type; std::cin >> type;

        if (type == 2) {
            int x, v; std::cin >> x >> v;

            a[x] = v;
            for (int i = 1; i <= n; ++i) {
                p[i] = p[i - 1] + a[i];
            }
        } else {
            int l, r; std::cin >> l >> r;

            int64_t mx = -1e18, mn = 1e18, mxp, mnp, mnx = 1e18, mxn = -1e18;
            for (int i = l; i <= r; ++i) {
                if (chmax(mx, p[i - 1])) {
                    mxp = i;
                }

                if (chmin(mn, p[i - 1])) {
                    mnp = i;
                }
            }

            for (int i = l; i <= mxp; ++i) {
                chmin(mnx, p[i - 1]);
            }

            for (int i = l; i <= mnp; ++i) {
                chmax(mxn, p[i - 1]);
            }

            int64_t res = std::abs(p[r] - p[l - 1]), 
                    tmx = std::max(std::abs(p[l - 1] - mx), std::min(std::abs(p[l - 1] - mnx), std::abs(mnx - mx))),
                    tmn = std::max(std::abs(p[l - 1] - mn), std::min(std::abs(p[l - 1] - mxn), std::abs(mxn - mn)));


            chmax(res, std::min(std::abs(p[r] - mx), tmx));
            chmax(res, std::min(std::abs(p[r] - mn), tmn));

            std::cout << res << '\n';
        }
    }

    return 0;
}
