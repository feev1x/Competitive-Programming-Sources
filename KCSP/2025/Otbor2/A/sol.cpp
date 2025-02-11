/**
 *    author:  feev1x
 *    created: 02.02.2025 11:01:48
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, w; std::cin >> n >> w;

    std::vector<int> a(n), b(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    int max = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] + b[i] > w && a[i - 1] + b[i - 1] > w) {
            max = std::max(max, b[i]);
        }
    }

    std::cout << max << '\n';
    return 0;
}
