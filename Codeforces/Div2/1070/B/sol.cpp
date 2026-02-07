#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    std::string t;

    int pos = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            pos = i;
            break;
        }
    }

    for (int i = pos; i < n; ++i) {
        t += s[i];
    }

    for (int i = 0; i < pos; ++i) {
        t += s[i];
    }

    int l = -1, res = 0;
    s = t;
    for (int i = 0; i < n; ++i) {
        bool old = (i && s[i - 1] == '0');

        if (!old && s[i] == '0') {
            l = i;
        } else if (old && s[i] == '1') {
            res = std::max(res, i - l);
        }
    }

    if (s.back() == '0') {
        res = std::max(res, n - l);
    }

    std::cout << res << '\n';
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
