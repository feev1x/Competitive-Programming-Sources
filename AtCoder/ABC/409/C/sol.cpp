/**
 *    author:  feev1x
 *    created: 13.06.2025 15:21:56
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l; std::cin >> n >> l;

    std::vector<int64_t> d(n), p(n);
    for (auto &u: d) {
        std::cin >> u;
    }

    std::vector<int64_t> cnt(l);

    for (int i = 1; i < n; ++i) {
        p[i] = (p[i - 1] + d[i - 1]) % l;
        cnt[p[i]]++;
    }

    cnt[0]++;

    int64_t res = 0;

    if (l % 3 == 0) {
        for (int i = 0; i < l; ++i) {
            res += cnt[i] * cnt[(i + l / 3) % l] * cnt[(i + 2 * l / 3) % l];
        }
    }

    std::cout << res / 3 << '\n';
    return 0;
}
