/**
 *    author:  feev1x
 *    created: 29.01.2025 20:35:20
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n = 5;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (int i = 0; i + 1 < n; ++i) {
        int j = i + 1;
        std::swap(a[i], a[j]);

        if (is_sorted(a.begin(), a.end())) {
            std::cout << "Yes\n";

            exit(0);
        }

        std::swap(a[i], a[j]);
    }

    std::cout << "No\n";
    return 0;
}
