/**
 *    author:  feev1x
 *    created: 05.04.2025 18:09:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n; std::cin >> n;

    int64_t cnt = 0;
    for (int64_t i = 1; i * i * 2 <= n; ++i) {
        if (i * i * 4 <= n) {
            cnt++;
        }

        if (i * i * 2 <= n) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
