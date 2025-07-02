/**
 *    author:  feev1x
 *    created: 16.05.2025 13:36:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> cnt(m + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        cnt[a[i]]++;
    }

    if (*std::min_element(cnt.begin() + 1, cnt.end()) == 0) {
        std::cout << 0 << '\n';

        exit(0);
    }

    for (int i = n; i >= 1; --i) {
        cnt[a[i]]--;

        if (!cnt[a[i]]) {
            std::cout << n - i + 1 << '\n';

            exit(0);
        }
    }

    return 0;
}
