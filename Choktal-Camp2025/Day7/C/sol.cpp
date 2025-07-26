/**
 *    author:  feev1x
 *    created: 07.07.2025 09:02:53
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) 
        std::cin >> a[i];

    int res = 1e9;
    for (int i = 1; i <= 2; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int x = 0; ; ++x) {
                for (int y = 0; y <= x; ++y) {
                    if (std::gcd(a[i] + y, a[j] + x - y) == 1) {
                        res = std::min(res, x);

                        goto end;
                    }
                }
            }

end:
            continue;
        }
    }

    std::cout << res << '\n';
    return 0;
}
