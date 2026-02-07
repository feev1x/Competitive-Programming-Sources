#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int b, w; std::cin >> b >> w;

    if (b > w) {
        std::swap(b, w);
    }

    int res = 0;
    for (int sz = 0; sz <= b + w; ++sz) {
        int vl = sz * sz;

        int bc = vl / 2, wc = (vl + 1) / 2;

        if (b >= bc && w >= wc) {
            res = sz;
        }
    }

    std::cout << res << '\n';
    return 0;
}
