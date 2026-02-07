#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    if (k % 2 == 0) {
        int num = __builtin_popcount(n);

        if (num == 1) {
            for (int i = 0; i < k - 1; ++i) {
                std::cout << n << ' ';
            }

            std::cout << "0\n";
            return;
        }

        if (k < num) {
            num = k;
        }

        num /= 2;

        for (int i = 0; i < k - num * 2; ++i) {
            std::cout << n << ' ';
        }
        
        int c = -1, b = -1, nw = 31, pos = -1;
        int res = 0, val = 0;
        for (int i = 0; i < num; ++i) {
            while (c == -1) {
                if (n >> nw & 1) {
                    c = nw--;
                    break;
                }

                nw--;
            }

            while (b == -1) {
                if (n >> nw & 1) {
                    b = nw--;
                    break;
                }

                nw--;
            }

            if (pos == -1) {
                pos = b;
            } else {
                std::cout << (((((n >> b) << b) - 1) ^ (1 << b)) ^ (1 << c)) << ' ';
                val |= 1 << c;
            }

            val |= 1 << b;

            std::cout << ((n >> b) << b) - 1 << ' ';

            c = -1, b = -1;
        }

        for (int i = 0; i < pos; ++i) {
            if (n >> i & 1) {
                continue;
            }

            res |= 1 << i;
        }

        std::cout << (res | val) << '\n';
    } else {
        for (int i = 0; i < k; ++i) {
            std::cout << n << " \n"[i == k - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
