/**
 *    author:  feev1x
 *    created: 30.01.2025 09:46:47
**/
#include <bits/stdc++.h>

inline void umin(int64_t &a, int64_t b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; int64_t S; std::cin >> n >> S;

    std::vector<int64_t> a(n), p(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end(), std::greater<>());

    for (int i = 0; i < n; ++i) {
        if (i)
            p[i] = p[i - 1];

        p[i] += a[i];
    }


    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int m = l + r >> 1;

        int64_t res = 0, nw = 0;
        for (int i = 0; i < m; ++i) {
            res += ((m - (i + 1)) - (i + 1) + 1) * a[i];
        }

        nw = res;
        for (int i = 1; i + m - 1 < n; ++i) {
            nw -= a[i - 1] * (m - 1);

            nw += 2 * (p[i + m - 2] - p[i - 1]);

            nw += (1 - m) * a[i + m - 1]; 

            res = std::min(res, nw);
        }

        if (res > S) {
            r = m - 1;
        } else {
            l = m + 1;
            ans = m;
        }
    }

    std::cout << ans << '\n';
    return 0;
}
