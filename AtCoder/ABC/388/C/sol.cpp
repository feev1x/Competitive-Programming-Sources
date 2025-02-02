/**
 *    author:  feev1x
 *    created: 11.01.2025 18:07:10
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int64_t cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += std::upper_bound(a.begin(), a.end(), a[i] / 2) - a.begin();
    }

    std::cout << cnt << '\n';
    return 0;
}
