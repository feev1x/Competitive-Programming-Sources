/**
 *    author:  feev1x
 *    created: 16.02.2025 21:23:06
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, q; std::cin >> n >> q;

        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        std::vector ans(30, std::vector(2, std::vector<int>(n + 1, n)));
        std::vector ans1(30, std::vector(2, std::vector<int>(n + 1, n)));
        std::array<bool, 30> val{};

        for (int i = n - 1; i >= 0; --i) {
             for (int j = 0; j < 30; ++j) {
                 if (val[j] < (a[i] >> j & 1)) {
                     ans[j][0][n - i - 1] = std::min(ans[j][0][n - i - 1], n - i - 1);
                 }


                 if (val[j] <= (a[i] >> j & 1)) {
                     ans1[j][0][n - i - 1] = std::min(ans1[j][0][n - i - 1], n - i - 1);
                 }

                 if ((val[j] ^ 1) < (a[i] >> j & 1)) {
                     ans[j][1][n - i - 1] = std::min(ans[j][1][n - i - 1], n - i - 1);
                 }

                 if ((val[j] ^ 1) <= (a[i] >> j & 1)) {
                     ans1[j][1][n - i - 1] = std::min(ans1[j][1][n - i - 1], n - i - 1);
                 }


                 val[j] ^= (a[i] >> j & 1);
             }
        }

        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 2; ++j) {
                int val = n, val1 = n;

                for (int k = n; k >= 0; --k) {
                    val = std::min(val, ans[i][j][k]);
                    val1 = std::min(val1, ans1[i][j][k]);

                    ans[i][j][k] = val;
                    ans1[i][j][k] = val1;
                }
            }
        }

        while (q--) {
            int x; std::cin >> x;
            
            int res = n, res1 = 0;
            for (int i = 29; i >= 0; --i) {
                bool vl = x >> i & 1;

                if (ans1[i][vl][res1] >= res1) {
                    res1 = std::min(res, ans1[i][vl][res1]);
                }

                assert(ans1[i][vl][res1] <= ans[i][vl][res1]);
                
                if (res >= ans[i][vl][res1]) {
                    res = std::max(res1, ans[i][vl][res1]);
                }

            }

            std::cout << res << " \n"[!q];
        }
    }
    return 0;
}
