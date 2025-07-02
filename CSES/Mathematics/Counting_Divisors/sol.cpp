/**
 *    author:  feev1x
 *    created: 26.03.2025 16:18:53
**/
#include <bits/stdc++.h>

constexpr int N = 1e6 + 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> cnt(N);

    cnt[1] = 1;
    for (int i = 2; i < N; ++i) {
        int u = i;

        for (int j = 2; j * j <= i; ++j) {
            if (u % j == 0) {
                u = j;

                break;
            }
        }

        int x = i, cn = 1;
        while (x % u == 0) {
            x /= u;
            
            cn++;
        }

        cnt[i] = cnt[x] * cn;
    }

    int n; std::cin >> n;
    while (n--) {
        int x; std::cin >> x;

        std::cout << cnt[x] << '\n';
    }
    return 0;
}
