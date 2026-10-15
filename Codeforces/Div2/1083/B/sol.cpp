#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int k = 1;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            k *= i;

            while (n % i == 0) {
                n /= i;
            }
        }
    }

    std::cout << k * n << '\n';
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
