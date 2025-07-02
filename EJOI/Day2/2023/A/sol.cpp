/**
 *    author:  feev1x
 *    created: 02.05.2025 14:14:52
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
        }
    }

    auto b = a;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = i * n + j;
        }
    }


    return 0;
}
