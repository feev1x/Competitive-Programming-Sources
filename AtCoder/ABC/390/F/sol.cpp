/**
 *    author:  feev1x
 *    created: 12.02.2025 11:27:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::vector<int>> pos(n + 1);
    for (int i = 0; i <= n; ++i) {
        pos[i].emplace_back(-1);
    }

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];

        pos[a[i]].emplace_back(i);
    }

    for (int i = 0; i <= n; ++i) {
        pos[i].emplace_back(n);
    }

    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
        int64_t l = i - std::max(*--std::upper_bound(pos[a[i] - 1].begin(), pos[a[i] - 1].end(), i),
                *--std::lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i));
        int64_t r = *std::upper_bound(pos[a[i] - 1].begin(), pos[a[i] - 1].end(), i) - i;

        res += l * r;
    }

    std::cout << res << '\n';
    return 0;
}
