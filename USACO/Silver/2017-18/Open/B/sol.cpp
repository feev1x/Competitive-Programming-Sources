/**
 *    author:  feev1x
 *    created: 10.02.2025 09:47:05
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("lemonade.in", "r", stdin);
    std::freopen("lemonade.out", "w", stdout);
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> w(n);
    for (auto &u: w) {
        std::cin >> u;
    }

    std::sort(w.begin(), w.end(), std::greater<>());

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt <= w[i]) {
            cnt++;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
