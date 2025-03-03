/**
 *    author:  feev1x
 *    created: 26.02.2025 16:56:29
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<std::array<int, 18>> anc(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p; std::cin >> p;

        anc[i][0] = p;

        for (int j = 1; j < 18; ++j) {
            anc[i][j] = -1;
        }
    }

    for (int j = 0; j < 18; ++j) {
        anc[1][j] = -1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 18; ++j) {
            if (anc[i][j - 1] == -1) {
                anc[i][j] = -1;
            } else {
                anc[i][j] = anc[anc[i][j - 1]][j - 1];
            }
        }
    }

    while (q--) {
        int x, k; std::cin >> x >> k;

        for (int i = 0; x != -1 && i < 18; ++i) {
            if (k >> i & 1) {
                x = anc[x][i];
            }
        }

        std::cout << x << '\n';
    }
    return 0;
}
