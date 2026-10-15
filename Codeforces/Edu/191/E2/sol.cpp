#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;
    int c = 32 - __builtin_clz(n);
    std::vector<std::string> s(c);
    std::vector<std::pair<int, int>> gt;
    for (int i = 0; i < c; ++i) {
        std::cin >> s[i];
        int cn = std::count(s[i].begin(), s[i].end(), '1');
        gt.emplace_back(cn, i);
    }
    std::sort(gt.begin(), gt.end(), std::greater<>());
    std::vector<int> p(n);
    int pw = 0;
    for (auto [cn, i]: gt) {
        for (int j = 0; j < n; ++j) p[j] |= (1 << pw) * (s[i][j] == '1');
        pw++;
    }
    std::sort(p.begin(), p.end());
    bool flag = true;
    for (int i = 0; i < n; ++i) if (p[i] != i + 1) flag = false;
    std::vector<int> cnt(n + 1);
    for (auto [cn, i]: gt) cnt[cn]++;
    int mx = *std::max_element(cnt.begin(), cnt.end());
    std::vector<int64_t> fac(mx + 1, 1);
    for (int i = 2; i <= mx; ++i) fac[i] = fac[i - 1] * i;
    int64_t res = 1;
    for (int i = 0; i <= n; ++i) res *= fac[cnt[i]];
    std::cout << res * flag << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int tt; std::cin >> tt;
    while (tt--) solve();
    return 0;
}
