/**
 *    author:  feev1x
 *    created: 25.07.2025 18:41:48
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1);
    std::vector<int64_t> p3(n + 1), s3(n + 1), p2(n + 1), s2(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        p2[i] = p3[i] = s2[i] = s3[i] = a[i];

        if (i > 2)
            p2[i] += p2[i - 2];

        if (i > 3)
            p3[i] += p3[i - 3];
    }

    for (int i = n - 2; i >= 1; --i) {
        s2[i] += s2[i + 2];

        if (i + 3 <= n)
            s3[i] += s3[i + 3];
    }

    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;

        int64_t res = 0;
        for (int64_t x = l - 1; x <= r; ++x) {
            if (s3[x] >= p2[x + 1] || !x || x + 1 > n)
                continue;

            res += ((x - l + 1) / 2) * ((r - x + 3) / 3);

            res += ((r - x + 3) / 3) - 1;
        }

        for (int64_t x = l - 1; x <= r; ++x) {
            if (s2[x] <= p3[x + 1] || !x || x + 1 > n)
                continue;

            res += ((r - x) / 2) * ((x - l + 4) / 3);

            res += ((x - l + 4) / 3) - 1;
        }

        if (r == n && p2[n - 1] > s3[n])
            res += (n - l + 1) / 2;

        if (l == 1 && s2[2] > p3[1])
            res += r / 2;

        std::cout << res << '\n';
    }
    return 0;
}
