#include <bits/stdc++.h>

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int sum = 0;
    std::vector<int> w(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> w[i];

        sum += w[i];
    }
    
    std::bitset<10005> bt;

    bt[0] = 1;
    for (int i = 1; i <= n; ++i) {
        bt |= bt << w[i];
    }

    int res = 0;
    for (int i = 1; i <= sum; ++i) {
        if (bt[i]) {
            res = std::max(res, i * (sum - i));
        }
    }

    std::cout << res << '\n';
    return 0;
}
