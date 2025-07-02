/**
 *    author:  feev1x
 *    created: 13.06.2025 15:16:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;
    
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (int x = 0; x <= n + 1; ++x) {
        int cnt = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] >= x) {
                cnt++;
            }
        }

        if (cnt < x) {
            std::cout << x - 1 << '\n';

            break;
        }
    }
    return 0;
}
