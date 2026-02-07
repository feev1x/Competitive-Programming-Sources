#include <bits/stdc++.h>

inline void solve(int n) {
    int a, b; std::cin >> a >> b;

    bool flag = false, fl = false;
    int idx = -1;
    for (int i = 0; i < 32; ++i) {
        if ((a + b) == (1 << i)) {
            flag = true;
            idx = i;
            break;
        }

        if (a + b + 1 == (1 << i)) {
            fl = true;
        }
    }

    if (flag) {
        std::cout << 2 + idx << ' ' << 2 + idx << '\n';

        for (int i = 3; i <= 2 + idx; ++i) {
            if (a >> (i - 3) & 1) {
                std::cout << i - 1 << ' ' << 1 << '\n';
            } else {
                std::cout << i - 1 << ' ' << 2 << '\n';
            }
        }

        return;
    }

    assert(fl);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt, n; std::cin >> tt >> n;

    while (tt--) {
        solve(n);
    }

    return 0;
}
