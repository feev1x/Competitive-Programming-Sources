#include <bits/stdc++.h>

inline void solve() {
    int n, m, d; std::cin >> n >> m >> d;

    int cnt = 1, sum = 0;
    while (cnt + 1 <= n && sum + m <= d) {
        cnt++;
        sum += m;
    }

    std::cout << n / cnt + (n % cnt > 0) << '\n';
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
