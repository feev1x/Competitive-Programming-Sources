/**
 *    author:  feev1x
 *    created: 16.05.2025 13:40:13
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    int64_t sum = 0, res = 0;
    for (auto &u: a) {
        std::cin >> u;

        sum += u;
    }

    for (auto u: a) {
        sum -= u;

        res += sum * u;
    }

    std::cout << res << '\n';
    return 0;
}
