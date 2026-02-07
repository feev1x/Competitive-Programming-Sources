#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k; std::cin >> n >> k;
    
    int cnt = 0;
    for (int64_t i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
    }

    if (n > 1) {
        cnt++;
    }

    if (cnt >= k) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
