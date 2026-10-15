#include <bits/stdc++.h>

constexpr int N = 1e6 + 5;

int sum[N], val[2 * N];
int nd[N][10];

inline void solve() {
    std::vector<int> cnt(10, 0);
    std::string s, ans; std::cin >> s;
    if (s.size() <= 2) return std::cout << s << '\n', void();
    int sm = 0, res = -1;
    for (auto u: s) cnt[u - '0']++, sm += u - '0';
    for (int i = 1; i < sm; ++i) {
        int cn = 0;
        bool flag = sum[i] + i == sm;
        for (int j = 0; flag && j < 10; ++j) flag = cnt[j] >= nd[i][j], cn += cnt[j] - nd[i][j];
        if (flag && cn > 1) { res = i; break; }
    }
    for (int j = 9; j >= 0; --j) while (cnt[j] > nd[res][j]) ans += char(j + '0'), cnt[j]--;
    while (res > 9) {
        std::string t;
        int u = res, sm = 0;
        while (u) t += char(u % 10 + '0'), sm += u % 10, u /= 10;
        std::reverse(t.begin(), t.end());
        ans += t, res = sm;
    }
    ans += char(res + '0');
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 0; i < 10; ++i) sum[i] = i, nd[i][i] = 1;
    for (int i = 10; i < N; ++i) {
        int u = i, sm = 0;
        while (u) sm += u % 10, u /= 10;
        for (int j = 0; j < 10; ++j) nd[i][j] = nd[sm][j];
        sum[i] = sum[sm] + sm, u = i;
        while (u) nd[i][u % 10]++, u /= 10;
    }
    int tt; std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
