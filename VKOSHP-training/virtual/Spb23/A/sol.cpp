/**
 *    author:  feev1x
 *    created: 14.11.2025 10:17:22
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n, m, k; std::cin >> n >> m >> k;

    std::cout << ((n + k - 1) / k) * ((m + k - 1) / k) << '\n';
    return 0;
}
