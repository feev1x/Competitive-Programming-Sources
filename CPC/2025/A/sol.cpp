#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y; std::cin >> x >> y;

    std::cout << ((x % 2 == 0) || (y % 2 == 0) ? "Yes" : "No") << '\n';
    return 0;
}
