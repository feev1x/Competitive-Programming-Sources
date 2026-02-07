#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int p, q, x, y; std::cin >> p >> q >> x >> y;

    if (p <= x && x < p + 100 && q <= y && y < q + 100) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}
