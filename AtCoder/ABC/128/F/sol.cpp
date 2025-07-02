/**
 *    author:  feev1x
 *    created: 29.03.2025 16:38:45
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n), suf(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    suf[n - 1] = a[n - 1];

    int64_t res = 0;
    for (int add = 1; add < n; ++add) {
        for (int i = n - 1 - add; i >= 0; i -= add) {
            suf[i] = suf[i + add] + a[i];
        }

        int64_t sum = 0;
        for (int i = 0; i < n; i += add) {
            sum += a[i];

            int A = n - i - 1, B = A - add;
            if (A <= i && (i - A) % add == 0 || A <= 0 || B <= 0) {
                continue;
            }

            res = std::max(res, suf[A] + sum);
        }
    }

    std::cout << res << '\n';
    return 0;
}
