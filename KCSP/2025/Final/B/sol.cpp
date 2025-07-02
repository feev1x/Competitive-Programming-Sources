/**
 *    author:  feev1x
 *    created: 15.06.2025 10:39:54
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int cnt = 0, mx = 1, nw = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            cnt++;
        }

        nw += a[i] - 1;
        mx = std::max(mx, nw + 1);
    }

    cnt += nw;

    std::cout << cnt << ' ' << mx << '\n';
    return 0;
}
