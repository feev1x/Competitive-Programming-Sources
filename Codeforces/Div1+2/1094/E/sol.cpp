#include <bits/stdc++.h>

inline int add(int64_t x) { std::cout << "I " << x << std::endl; int got; std::cin >> got; return got; }
inline int query(int64_t x) { std::cout << "Q " << x << std::endl; int got; std::cin >> got; return got; }
inline void ans(int k, int64_t c) { std::cout << "A " << k << ' ' << c << std::endl; }

inline void solve() {
    int n; std::cin >> n;
    int64_t mx = (1ll << n) - 1;
    std::cout << mx << std::endl;
    if (add(mx) == 1) {
        if (add(0) == 1) ans(2, mx);
        else {
            int got = query(1);
            if (got == 1) ans(1, mx);
            else {
                int64_t c = 0;
                for (int i = n - 1; i >= 0; --i) if (query(c + (1ll << i)) == 2) c += (1ll << i);
                ans(2, c);
            }
        }
    } else {
        int64_t c = 0;
        for (int i = n - 1; i >= 0; --i) if (query(c + (1ll << i)) == 2) c += (1ll << i);
        if (add(0) == 2) ans(3, mx);
        else {
            int got = query(1);
            if (got == 2) ans(1, c);
            else ans(3, mx ^ c);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
