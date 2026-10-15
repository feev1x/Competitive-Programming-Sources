#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t s, n, d; std::cin >> s >> n >> d;

    std::cout << std::min(n, (n + (d / s) - 1) / (d / s)) << '\n';

    return 0;
}
