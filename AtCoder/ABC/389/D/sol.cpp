/**
 *    author:  feev1x
 *    created: 29.01.2025 19:46:42
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int r; std::cin >> r;

    auto Dis = [&](double x, double y) {
        return sqrt(x * x + y * y);
    };

    auto Check = [&](int x, int y) {
        return std::max({Dis(x + 0.5, y + 0.5), Dis(x + 0.5, y - 0.5), Dis(x - 0.5, y + 0.5), Dis(x - 0.5, y - 0.5)}) <= r;
    };

    int y = 0;
    int64_t res = 0;
    for (int x = 0; Check(x, 0); ++x) {
        while (Check(x, y)) {
            y++;
        }

        while (!Check(x, y)) {
            y--;
        }

        if (x == 0) {
            res += y * 2 + 1;
        } else {
            res += (y + 1) * 2 + y * 2;
        }
    }

    std::cout << res << '\n';
    return 0;
}
