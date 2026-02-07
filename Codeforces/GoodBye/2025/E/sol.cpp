#include <bits/stdc++.h>

inline int64_t ask(int l, int r) {
    std::cout << "? " << l << ' ' << r << std::endl;

    int64_t got; std::cin >> got;

    return got;
}

inline void solve() {
    int n; std::cin >> n;

    auto Get = [&](auto &&self, int l, int r) -> int64_t {
        if (l == r) {
            return ask(l, r);
        }
        
        bool flag = false;
        int bl = l, br = r - 1, ans = -1;
        while (bl <= br) {
            int m = bl + br >> 1;

            int64_t ls = ask(l, m), rs = ask(m + 1, r);

            if (ls >= rs) {
                if (ls == rs) {
                    flag = true;
                } else {
                    flag = false;
                }

                br = m - 1, ans = m;
            } else {
                bl = m + 1;
            }
        }

        assert(ans != -1 && flag);

        return (ans - l + 1 > r - ans ? self(self, ans + 1, r) : self(self, l, ans));
    };

    int64_t res = Get(Get, 1, n);

    std::cout << "! " << res << std::endl;
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
