/**
 *    author:  feev1x
 *    created: 29.03.2025 18:02:06
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

    auto b = a;
    std::sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        std::cout << b.end() - std::upper_bound(b.begin(), b.end(), a[i]) + 1 << '\n';
    }
    return 0;
}
