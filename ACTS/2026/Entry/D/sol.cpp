#include <bits/stdc++.h>

constexpr int N = 30;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, y; std::cin >> n >> y;
    std::vector<int> a(n);
    for (auto &u: a) std::cin >> u;
    std::vector<bool> closed(N);
    std::string s;
    for (int i = n - 1; i >= 0; --i) {
        std::vector<bool> b(4);
        for (int j = 0; j < N; ++j) if (!closed[j]) {
            if (y >> j & 1) {
                if (a[i] >> j & 1) {
                    b[0] = true;
                } else {
                    b[1] = true;
                }
            } else {
                if (a[i] >> j & 1) {
                    b[2] = true;
                } else {
                    b[3] = true;
                }
            }
        }
        if (b[2]) {
            s += '^';
            y ^= a[i];
            continue;
        }
        s += '|';
        for (int j = 0; j < N; ++j) if (!closed[j]) {
            if ((y >> j & 1) && (a[i] >> j & 1)) closed[j] = true;
        }
    }
    std::reverse(s.begin(), s.end());
    std::cout << s << '\n';
    return 0;
}
