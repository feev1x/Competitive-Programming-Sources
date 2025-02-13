/**
 *    author:  feev1x
 *    created: 11.02.2025 16:35:43
**/
#include <bits/stdc++.h>

constexpr int N = 1005;

int a[N][N];

int main() {
    std::freopen("paintbarn.in", "r", stdin);
    std::freopen("paintbarn.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k; std::cin >> n >> k;    

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j < x2; ++j) {
            a[j][y1]++;
            a[j][y2]--;
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int val = 0;

        for (int j = 0; j < N; ++j) {
            val += a[i][j];

            if (val == k) {
                cnt++;
            }
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
