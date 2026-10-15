#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k; std::cin >> n >> k;
    std::vector a(5, std::vector<int>());
    for (int i = 0; i < n; ++i) {
        int t, x, y, c; std::cin >> t >> x >> y >> c;
        a[t].emplace_back(x, y, c);
    }
    return 0;
}
