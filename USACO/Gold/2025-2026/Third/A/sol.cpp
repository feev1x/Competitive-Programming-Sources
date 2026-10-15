#include <bits/stdc++.h>

struct Bit {
    std::vector<int> p;
    int n;
    Bit(int n) : n(n) { p.resize(n + 1); }
    inline void update(int r, int x) { for (; r <= n; r += r & -r) p[r] += x; }
    inline int get(int r) {
        int res = 0;
        for (; r > 0; r -= r & -r) res += p[r];
        return res;
    }
};

inline void solve() {
    int n, cn = 0; std::cin >> n;
    int64_t inv = 0, sum = 0;
    std::vector<int> p(n + 1), cnt(5 * n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> p[i], sum += std::abs(p[i] - i);
    for (int i = 1; i <= n; ++i) if (p[i] >= i) cnt[p[i] - i]++, cn++;
    cn -= cnt[0];
    Bit bit(n + 1);
    for (int i = n; i >= 1; --i) inv += bit.get(p[i]), bit.update(p[i], 1);
    std::vector<int> res;
    for (int s = 0; s < n; ++s) {
        int pos = n - s;
//        std::cout << sum << ' ' << inv << '\n';
        if (sum / 2 >= inv) res.emplace_back(s);
        inv -= n - p[pos], inv += p[pos] - 1;
        sum -= cn, sum += n - cn - 1;
        sum -= std::abs(p[pos] - n);
        sum += std::abs(p[pos] - 1);
        cnt[p[pos] + s]++;
        cn++;
        cn -= cnt[s + 1];
    }
    std::cout << res.size() << '\n';
    for (auto u: res) std::cout << u << ' ';
    std::cout << '\n';
}

// 2 1 5 4 3
// 1 2 3 4 5

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
