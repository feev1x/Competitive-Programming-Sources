#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    std::sort(a.begin(), a.end(), std::greater<>());
    int res = n;
    for (int i = 0; i < n; ++i) res = std::min(res, i + a[i]);
    std::cout << res << '\n';
    return 0;
}
