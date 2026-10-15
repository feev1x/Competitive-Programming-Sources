#include <bits/stdc++.h>

using BT = std::bitset<25005>;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    BT b;
    b[0] = 1;
    int sum = 0;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
        b = b | (b << u);
        sum += u;
    }
    int res = sum;
    for (int i = 0; i <= sum; ++i) {
        if (b[i]) {
            res = std::min(res, std::abs(sum - 2 * i));
        }
    }
    std::cout << res << '\n';
    return 0;
}
