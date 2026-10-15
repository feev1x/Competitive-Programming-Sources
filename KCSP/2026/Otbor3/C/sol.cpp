#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    short n; std::cin >> n;
    std::vector<std::vector<short>> p(n, std::vector<short>(n, -1));
    std::vector<int> a(n), b(n);
    for (auto &u: a) {
        std::cin >> u;
    }
    b = a;
    for (auto &u: a) {
        u %= n;
    }
    std::vector<short> ls(n, -1);
    ls[0] = -2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            p[i][(j + a[i]) % n] = ls[j];
            assert(ls[j] != i);
        }
        for (int j = 0; j < n; ++j) {
            if (p[i][(j + a[i]) % n] != -1) {
                ls[(j + a[i]) % n] = i;
            }
        }
    }

    if (ls[0] == -2) {
        std::cout << "0\n";
        return 0;
    }

    std::vector<int> res;
    int i = ls[0], j = 0;
    while (i != -2) {
        res.emplace_back(b[i]);
        int oi = i;
        i = p[i][j];
        j -= a[oi];
        if (j < 0) {
            j += n;
        }
    }
    std::cout << res.size() << '\n';
    for (auto u: res) {
        std::cout << u << '\n';
    }
    return 0;
}
