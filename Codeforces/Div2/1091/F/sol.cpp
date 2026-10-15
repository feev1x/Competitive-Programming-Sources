#include <bits/stdc++.h>

inline void solve() {
    int x1, x2; std::cin >> x1 >> x2;
    auto Get = [&](int x) {
        int val = (x2 - 1 - x) >> 1, ml = 1, cnt = 0;
        if (val < 0) return 0; 
        for (int i = 20; i >= 0; --i) {
            if (val >> i & 1) {
                if (x >> i & 1) return cnt + (1 << i + 1) * ml;
                cnt += (1 << i) * ml;
            } else if (x >> i & 1) ml *= 2;
        }
        return cnt + ml;
    };
    int ans = 0, cnt = -1;
    for (int x = 0; x < x1; ++x) {
        int got = Get(x);
        if (cnt == -1 || got < cnt) cnt = got, ans = x;
    }
    std::cout << ans + 1 << ' ' << x1 << '\n';
}

/**
 * count l such that (l & x) ^ l <= (sum - x) / 2
**/

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
