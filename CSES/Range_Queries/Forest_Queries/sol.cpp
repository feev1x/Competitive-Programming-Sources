/**
 *    author:  feev1x
 *    created: 04.03.2025 16:30:28
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> pref(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        std::string s; std::cin >> s;

        s = " " + s;

        for (int j = 1; j <= n; ++j) {
            if (s[j] == '*') {
                a[i][j] = 1;
            }

            pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + a[i][j];
        }
    }

    while (q--) {
        int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

        std::cout << pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1] << '\n';
    }
    return 0;
}
