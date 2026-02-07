#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::array<int, 3> a;
    for (auto &u: a) {
        std::cin >> u;
    }

    int m; std::cin >> m;

    std::sort(a.begin(), a.end());

    int cnt = 1, nw = 0;
    for (auto u: a) {
        if (nw + u > m) {
            cnt++;
            nw = u;
        } else {
            nw += u;
        }
    }

    std::cout << cnt << '\n';
    return 0;
}
