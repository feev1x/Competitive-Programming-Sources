#include <bits/stdc++.h>

#define int int64_t

inline void solve() {
    int x, y; std::cin >> x >> y;

    int p = 0, q = 0, bz = 0, sb = 0, oq = 0, op = 0;
    bool bad = false;
    for (int i = 30; i >= 0; --i) {
        if (x >> i & 1ll) {
            if (y >> i & 1ll) {
                bad = true;
            } else {
                op |= 1ll << i;
            }

            if (!bad) {
                p |= 1ll << i;
            }
        } else {
            if (!(y >> i & 1ll) && !bad) {
                bz = 1ll << i;
            }

            if (!(y >> i & 1ll) && bad) {
                oq |= 1ll << i;
                op |= 1ll << i;
            }

            if (y >> i & 1ll) {
                q |= 1ll << i;
                oq |= 1ll << i;
            }
        }
    }

    if (!bad) {
        bz = 0;
    }

    for (int i = 0; 1ll << i <= bz; ++i) {
        if (q >> i & 1ll) {
            q ^= 1ll << i;
        }

        if (p >> i & 1ll) {
            p ^= 1ll << i;
        }
    }

    if (std::min(std::abs(x - (p + bz)), std::abs(x - op)) > std::min(std::abs(y - (q + bz)), std::abs(y - oq))) {
        if (std::abs(y - (q + bz)) < std::abs(y - oq)) {
            std::cout << x << ' ' << (q + bz) << '\n';
        } else {
            std::cout << x << ' ' << oq << '\n';
        }
    } else {
        if (std::abs(x - (p + bz)) < std::abs(x - op)) {
            std::cout << (p + bz) << ' ' << y << '\n';
        } else {
            std::cout << op << ' ' << y << '\n';
        }
    }
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
