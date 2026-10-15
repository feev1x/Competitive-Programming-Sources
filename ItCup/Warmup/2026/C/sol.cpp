#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    int ls = a[0], pos = -1;
    for (int i = 1; i < n; ++i) {
        ls = ls % n + 1;
        if (ls == a[i]) continue;
        pos = i + 1;
        break;
    }
    if (pos == -1) std::cout << "NO\n";
    else std::cout << "YES\n" << pos << '\n';
    return 0;
}
