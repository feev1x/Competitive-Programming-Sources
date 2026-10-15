#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;
    std::vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    int64_t sum = 0, l = 1, r = 2;
    for (int i = n; i >= 1; --i) {
        sum += a[i] * (n - i + 1);
        if (sum > 0) p[i] = r++;
        else p[i] = l--;
    }
    for (int i = 1; i <= n; ++i) std::cout << p[i] - l << " \n"[i == n];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
