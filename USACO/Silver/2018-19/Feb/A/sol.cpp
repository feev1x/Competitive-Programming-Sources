/**
 *    author:  feev1x
 *    created: 11.02.2025 14:00:33
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

int main() {
    std::freopen("herding.in", "r", stdin);
    std::freopen("herding.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> x(n);
    for (auto &u: x) {
        std::cin >> u;
    }

    std::sort(x.begin(), x.end());
    
    int mx = 0, sum = 0, mn = INF;

    for (int i = 0; i < n; ++i) {
        if (i) {
            sum += x[i] - x[i - 1] - 1;
        }
        
        int cnt = std::upper_bound(x.begin(), x.end(), x[i] + n - 1) - std::lower_bound(x.begin(), x.end(), x[i]);

        if (cnt == n - 1 && x[n - 2] == x[i] + n - 2 && i == 0 || x[i] + n - 1 > x[n - 1]) {
            continue;
        }

        mn = std::min(mn, n - cnt);
    }

    mx = std::max(mx, sum - std::min(x[1] - x[0] - 1, x[n - 1] - x[n - 2] - 1));

    std::cout << mn << '\n' << mx << '\n';

    return 0;
}
