#include <bits/stdc++.h>

#define int64_t __int128
constexpr int64_t INF = 3e18;

inline void output(__int128 x) {
    if (x < 0) std::cout << '-', x = -x;
    if (x > 9) output(x / 10);
    std::cout << (int)(x % 10);
}

inline void solve() {
    long long n, k; std::cin >> n >> k;
    std::vector<long long> a(n), b(n);
    for (auto &u: a) std::cin >> u;
    for (auto &u: b) std::cin >> u;
    auto Get2 = [&](int64_t max, int64_t min) {
        __int128 cost = 0;
        for (int i = 0; i < n; ++i) cost += std::max((int64_t)0, std::max(a[i] - max, min - b[i]));
        return cost;
    };
    auto Get = [&](int64_t m) {
        int64_t l = 0, r = INF; __int128 ans = INF;
        while (l <= r) {
            int64_t mid = l + r >> 1;
            __int128 ans1 = Get2(mid + m, mid), ans2 = Get2(mid + 1 + m, mid + 1);
            ans = std::min(ans, std::min(ans1, ans2));
            if (ans2 - ans1 > 0) r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    };
    int64_t l = -INF, r = INF, ans = INF;
    while (l <= r) {
        int64_t m = l + r >> 1;
        if (Get(m) > k) l = m + 1;
        else r = m - 1, ans = m;
    }
    output(ans); std::cout << '\n';
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
