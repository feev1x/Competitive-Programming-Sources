#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::array<int, 3> a;
    for (auto &u: a) std::cin >> u;
    std::sort(a.begin(), a.end());
    std::cout << (a[0] + a[1] >= a[2] ? "YES" : "NO") << '\n';
    return 0;
}
