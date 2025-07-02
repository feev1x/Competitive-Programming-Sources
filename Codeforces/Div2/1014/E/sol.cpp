/**
 *    author:  feev1x
 *    created: 29.03.2025 21:36:01
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m, k; std::cin >> n >> m >> k;

        auto IsSide = [&](int i, int j) {
            if (i == n || i == 1) {
                return j != m && j != 1;
            } else if (j == m || j == 1) {
                return i != n && i != 1;
            }

            return false;
        };

        int64_t cnt = (int64_t)n * m, cnt_s = 0;

        cnt_s += n * 2;
        cnt_s += m * 2;
        cnt_s -= 8;

        cnt -= n * 2;
        cnt -= m * 2;
        cnt += 8;

        bool odd = false;
        for (int i = 0; i < k; ++i) {
            int x, y, col; std::cin >> x >> y >> col;

            if (IsSide(x, y)) {
                if (col) {
                    odd = !odd;
                }

                cnt_s--;
            } else {
                cnt--;
            }
        }

        cnt = binpow(2, cnt % (MOD - 1));

        if (cnt_s) {
            cnt_s = binpow(2, (cnt_s - 1) % (MOD - 1));
        } else {
            if (!odd) {
                cnt_s = 1;
            }
        }

        cnt = mul(cnt, cnt_s);

        std::cout << cnt << '\n';
    }
    return 0;
}
