#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k; std::cin >> n >> m >> k;

    std::vector<int> a(n), b(m), c(k);
    for (auto &u: a)
        std::cin >> u;

    for (auto &u: b)
        std::cin >> u;

    for (auto &u: c)
        std::cin >> u;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::sort(c.begin(), c.end());

    for (int i = 0; i < n; ++i) {
        int l = 
    }
    return 0;
}
