#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<std::string> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    std::string t;
    for (int i = 0; i < n; ++i) {
        if (t + a[i] >= a[i] + t) {
            t = a[i] + t;
        } else {
            t += a[i];
        }
    }

    std::cout << t << '\n';
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
