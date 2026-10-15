#include <bits/stdc++.h>

#define int int64_t

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

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    // slego menshe
    std::vector<int> p(n + 1), cnt(n + 1), pos(n + 1);
    Bit bit(n + 1);
    int64_t nw = 0, res = 1e18;
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
        pos[p[i]] = i;
        cnt[i] = bit.get(p[i]);
        nw += i - 1 - cnt[i];
        bit.update(p[i], 1);
    }
    for (int x = 1; x <= n; ++x) {
        int i = pos[x];
        int64_t rnw = nw;
        rnw += x - 1 - cnt[i];
        rnw -= i - 1 - cnt[i];
        nw -= i - 1 - cnt[i];
        res = std::min(res, nw);
        nw = rnw;
    }
    std::cout << res << '\n';
    return 0;
}
