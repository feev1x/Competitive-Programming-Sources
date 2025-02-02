/**
 *    author:  feev1x
 *    created: 29.01.2025 20:38:35
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] * a[1] != a[i] * a[0]) {
            std::cout << "No\n";
            
            exit(0);
        }
    }

    std::cout << "Yes\n";
    return 0;
}
