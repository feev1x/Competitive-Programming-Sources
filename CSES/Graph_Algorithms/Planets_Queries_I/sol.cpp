/**
 *    author:  feev1x
 *    created: 04.03.2025 00:04:01
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<std::array<int, 30>> anc(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> anc[i][0];
    }

    for (int j = 1; j < 30; ++j) {
        for (int i = 1; i <= n; ++i) {
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }
    }

    while (q--) {
        int x, k; std::cin >> x >> k;

        for (int i = 0; i < 30; ++i) {
            if (k >> i & 1) {
                x = anc[x][i];
            }
        }

        std::cout << x << '\n';
    }
    return 0;
}
