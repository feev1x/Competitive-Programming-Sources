#include <bits/stdc++.h>

constexpr int N = 2e5 + 5;

inline void solve() {
    int n, q; std::cin >> n >> q;
    std::vector<bool> isq(n + 1), can2(n + 1);
    std::vector<int> min2(n + 1, n + 1);
    for (int i = 1; i * i <= n; ++i) isq[i * i] = true; 
    for (int x = 1; x <= n; ++x) for (int i = 1; i * i <= x; ++i) if (isq[x - i * i]) { can2[x] = true; break; }
    for (int x = 1; x <= n; ++x) for (int i = sqrt(x) + 1; i * i <= n; ++i) if (isq[i * i - x]) { min2[x] = i * i; break; }
    auto Check = [&](int a, int b) {
        if (a > b) std::swap(a, b);
        return can2[b - a] || a + min2[b - a] <= n || b - min2[b - a] >= 1;
    };
    while (q--) {
        int a, b; std::cin >> a >> b;
        if (a > b) std::swap(a, b);
        if (isq[b - a]) {
            std::cout << "1\n";
            continue;
        }
        if (Check(a, b)) {
            std::cout << "2\n";
            continue;
        }
        bool flag = false;
        for (int i = 1; !flag && i * i + a <= n; ++i) if (Check(i * i + a, b)) flag = true;
        for (int i = 1; !flag && a - i * i >= 1; --i) if (Check(a - i * i, b)) flag = true;
        std::cout << (flag ? 3 : 4) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
