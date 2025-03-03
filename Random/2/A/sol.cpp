/**
 *    author:  feev1x
 *    created: 15.02.2025 08:09:22
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, a, b; std::cin >> n >> a >> b;

    std::cout << (a - std::min(a, b)) << '\n' << std::min(n - b, a) << '\n';
    return 0;
}
