#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int a, b, c; std::cin >> a >> b >> c;

    std::cout << std::max(0, n - a - b - c) << '\n' << n - std::max({a, b, c}) << '\n';
}
