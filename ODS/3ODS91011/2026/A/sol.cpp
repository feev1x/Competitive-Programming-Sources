#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n);
    std::map<int, int> mp;
    for (auto &u: a) {
        std::cin >> u;
        mp[u]++;
    }
    while (q--) {
        int x, y; std::cin >> x >> y;
        std::cout << n - mp[x] - mp[y] + (x == y ? mp[x] : 0) << '\n';
    }
    return 0;
}
