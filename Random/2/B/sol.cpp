/**
 *    author:  feev1x
 *    created: 15.02.2025 08:19:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t k, x, n; std::cin >> k >> x >> n;    

    if (x == k) {
        std::cout << 1 + (n - k) / (2 * (k - 1)) << '\n';

        exit(0);
    }

    if (x == 1) {
        std::cout << (n - 1) / (2 * (k - 1)) + 1 << '\n';

        
        exit(0);
    }

    int64_t cnt = (n - x) / (2 * (k - 1)), cnt1 = ((n - k - (k - x)) / (2 * (k - 1)));

    if (n < k + (k - x)) {
        cnt1--;
    }

    std::cout << cnt + cnt1 + 2 << '\n';
    return 0;
}
