/**
 *    author:  feev1x
 *    created: 11.01.2025 18:02:23
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, d; std::cin >> n >> d;    

    std::vector<int> t(n), l(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i] >> l[i];
    }

    for (int k = 1; k <= d; ++k) {
        int mx = 0;

        for (int i = 0; i < n; ++i) {
            mx = std::max(mx, t[i] * (l[i] + k));
        }

        std::cout << mx << '\n';
    }
    return 0;
}
