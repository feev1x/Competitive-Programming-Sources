#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    auto Get = [&](int x) {
        for (int i = (x + 1) % n, nw = 2; i != x; i = (i + 1) % n, nw++) if (std::abs(a[i] - nw) > 1) return false;
        return true;
    };
    for (int i = 0; i < n; ++i) {
        if (std::abs(a[i] - 1) <= 1 && Get(i)) {
            std::cout << "YES\n" << i + 1 << '\n';
            return 0;
        }
    }
    std::cout << "NO\n";
    return 0;
}
