#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; int64_t d; std::cin >> n >> d;

    std::vector<int64_t> c(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> c[i];
    }

    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;

        int64_t ls = 0, res = 0;
        for (int i = r - 1; i >= l; --i) {
            int64_t df = c[i + 1] - c[i];

            if (df < ls) {
                int64_t cnt = (ls - df + d - 1) / d;
                res += cnt;

                ls = df + cnt * d;
            } else {
                ls = df;
            }

            ls -= df;
        }

        std::cout << (ls > c[l] ? -1 : res) << '\n';
    }

    return 0;
}
