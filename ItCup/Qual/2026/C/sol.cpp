#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m; std::cin >> n >> m;
    std::cout << ((n >> m & 1) ? "YES" : "NO") << '\n';
    return 0;
}
