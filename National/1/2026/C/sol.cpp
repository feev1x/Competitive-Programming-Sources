#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;

    int x = std::abs(x1 - x2), y = std::abs(y1 - y2);


    std::cout << std::max(x + y - 1, 0) << '\n';

    return 0;
}
