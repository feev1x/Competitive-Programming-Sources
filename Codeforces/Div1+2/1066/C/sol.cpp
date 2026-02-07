/**
 *    author:  feev1x
 *    created: 24.11.2025 14:51:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k, q; std::cin >> n >> k >> q;

        std::vector<int> val(n + 1);
        // 1 = only min
        // 2 = only mex
        // 3 = both

        std::vector<std::pair<int, int>> qq;
        for (int i = 0; i < q; ++i) {
            int c, l, r; std::cin >> c >> l >> r;

            if (c == 1) {
                for (int j = l; j <= r; ++j)
                    if (val[j] >= 2)
                        val[j] = 3;
                    else
                        val[j] = 1;
            } else {
                for (int j = l; j <= r; ++j)
                    if (val[j] == 1 || val[j] == 3)
                        val[j] = 3;
                    else
                        val[j] = 2;
            }
        }

        std::vector<int> a(n + 1);

        int nw = 0;
        for (int i = 1; i <= n; ++i) {
            if (val[i] == 1)
                a[i] = k;
            else if (val[i] == 3)
                a[i] = k + 1;
            else {
                a[i] = nw;

                nw = (nw + 1) % k;
            }

            std::cout << a[i] << " \n"[i == n];
        }

    }
    return 0;
}
