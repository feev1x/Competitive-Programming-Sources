/**
 *    author:  feev1x
 *    created: 29.03.2025 18:09:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(2 * n + 1), pos(2 * n + 1);
        for (int i = 1; i <= 2 * n; ++i) {
            std::cin >> a[i];

            if (!pos[a[i]]) {
                pos[a[i]] = i;
            } else {
                pos[a[i] + n] = i;
            }
        }

        int cnt = 0;
        for (int i = 2; i <= 2 * n; ++i) {
            if (pos[a[i]] == i && pos[a[i - 1]] == i - 1 && std::abs(pos[a[i]] - pos[a[i] + n]) > 1 && 
                    std::abs(pos[a[i - 1]] - pos[a[i - 1] + n]) > 1 && std::abs(pos[a[i] + n] - pos[a[i - 1] + n]) == 1) {
                cnt++;
            }
        }

        std::cout << cnt << '\n';
    }
    return 0;
}
